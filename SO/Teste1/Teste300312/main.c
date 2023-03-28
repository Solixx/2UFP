#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int fds2[2];

void testeModeloEx2C();
void teste300312Ex3();
void teste300312Ex3Tentativa2(char *argv[]);
void teste300312Ex4a();
void chatGPTEx();
void show();

int main(int argc, char *argv[])
{
    teste300312Ex3Tentativa2(argv);
    return 0;
}

void show()
{
    int i,c;
    write(1,"\n",1);
    while((i=read(fds2[0],&c,1))!=0) write(1,&c,1);
    write(1,"\n",1);
    close(fds2[0]);
}

void SIG1(){
    printf("Erro na abertura do ficheiro normal\n");
}

void SIG2(){
    printf("Erro na abertura do ficheiro encriptado\n");
}

void testeModeloEx2C(){
    int pid,i,c,fds1[2];
    pipe(fds1);
    pipe(fds2);
    if((pid=fork())==-1) perror("fork:");
    else {
        if (pid==0) {
            close(fds1[1]);
            close(fds2[0]);
            while((i=read(fds1[0],&c,1))!=0){
                if (islower(c))
                    c=toupper(c);
                write(fds2[1],&c,1);
            }
            close(fds1[0]);
            close(fds2[1]);
            kill(getppid(), SIGUSR1);
            exit(0);
        }
        else{
            signal(SIGUSR1, show);
            close(fds2[1]);
            close(fds1[0]);
            while((i=read(0,&c,1))!=0) write(fds1[1],&c,1);
            close(fds1[1]);
            waitpid(pid,NULL,0);
        }
    }
}

void teste300312Ex3(){

    int n = 3;
    int fd[n];
    char *fil = NULL;
    pid_t pid[n];

    for (int i = 0; i < n; ++i) {
        scanf("%s", fil);

        pid[i] = fork();
        if(pid[i] == -1){
            perror("fork");
            return;
        } else{
            int k, c, fdC;

            fd[i] = open(fil, O_RDONLY, 0444);
            if(fd[i] == -1){
                kill(getpid(), SIGUSR1);
                exit(1);
            }

            strcat(fil, ".crypt");
            fdC = open(fil, O_CREAT | O_TRUNC | O_WRONLY, 0644);
            if(fdC == -1){
                kill(getpid(), SIGUSR2);
                exit(2);
            }

            while ((k = read(fd[i], &c, 1)) != 0){
                c = toupper(c) + 3;
                if(c > 'Z'){
                    c = c - (26+3);
                }
                write(fdC, &c, 1);
            }
            exit(0);
        }
    }
    int i = 0, l, status;
    signal(SIGUSR1, SIG1);
    signal(SIGUSR2, SIG2);
    for (int j = 0; j < n; ++j) {
        waitpid(pid[i], &status, 0);
        if(WIFEXITED(status)){
            if(WEXITSTATUS(status) == 1){
                printf("Erro na leitura do ficheiro normal\n");
            } else if(WEXITSTATUS(status) == 2){
                printf("Erro na leitura do ficheiro encriptado\n");
            } else{
                printf("Correu Bem\n");
            }
        }
        i++;
    }
}

void teste300312Ex4a(){

    int fd = open("outfile", O_CREAT | O_TRUNC | O_WRONLY, 0644);

    if(fd < 0) {
        perror("open");
        exit(0);
    }

    pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(1);
    } else if(pid == 0){
        //dup2(fd, STDOUT_FILENO);
        execl("/bin/sh", "sh", "-c", "ls -al | wc -l > outfile", NULL);
        perror("execl");
        exit(2);
    } else{
        int status;
        waitpid(pid, &status, 0);
        close(fd);
    }
}

void chatGPTEx(){

    int N = 5;
    int arr[] = {1,2,3,4,6}, fds[N][2];

    for (int i = 0; i < N; ++i) {
        pipe(fds[i]);
    }
    for (int i = 0; i < N; i += 2) {
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return;
        } else if(pid == 0){
            int soma = 0;
            close(fds[i][0]);
            if(i == N-1){
                soma = arr[i];
            } else{
                soma = arr[i] + arr[i+1];
            }
            write(fds[i][1], &soma, sizeof(int));
            close(fds[i][1]);
            exit(0);
        }
    }
    int total = 0;
    for (int i = 0; i < N; i += 2) {
        close(fds[i][1]);
        int soma;
        read(fds[i][0], &soma, sizeof (int));
        total += soma;
        close(fds[i][0]);
        waitpid(0, NULL, 0);
    }

    printf("Soma: %d\n", total);
}

void teste300312Ex3Tentativa2(char *argv[]){

    int N = 3;

    for (int i = 0; i < N; ++i) {
        pid_t pid = fork();
        if(pid == -1){
            perror("fork");
            return;
        } else if (pid == 0){
            int fd, fdCrypt, k, c;
            char filename[100];

            sprintf(filename, "%s.crypt", argv[i+1]);

            fd = open(argv[i+1], O_RDONLY);
            if(fd == -1){
                kill(getppid(), SIGUSR1);
                exit(1);
            }

            fdCrypt = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
            if(fdCrypt == -1){
                kill(getppid(), SIGUSR2);
                exit(2);
            }

            while ((k = read(fd, &c, 1)) != 0){
                c = toupper(c) + 3;
                if(c > 'Z'){
                    c = c - 26;
                }
                write(fdCrypt, &c, 1);
            }
            exit(0);
        }
    }

    signal(SIGUSR1, SIG1);
    signal(SIGUSR2, SIG2);
    for (int i = 0; i < N; ++i) {
        int status;
        waitpid(-1, &status, 0);
        if(WIFEXITED(status)){
            if(WEXITSTATUS(status) == 1){
                printf("Erro na leitura do ficheiro original\n");
            } else if(WEXITSTATUS(status) == 2){
                printf("Erro na leitura do ficheiro encriptado\n");
            } else{
                printf("Sucesso\n");
            }
        }
    }
}