#include <stdio.h>
#include <string.h>

void teste_2021_ex1();
void freq2_2022_ex1();
void freq2_2022_ex2();
void freq2_2022_ex3();
void freq2_2022_ex4();

int main() {

    //teste_2021_ex1();
    //freq2_2022_ex1();
    //freq2_2022_ex2();
    //freq2_2022_ex3();
    freq2_2022_ex4();

    return 0;
}

void teste_2021_ex1(){
    int max = 0, maxDia = 0, min = 0, minDia = 0, preco = 0, n = 0, i, aumento = 0, aumentoMax = 0, aumentoMaxDia = 0, temp = 0, count = 0, countMax = 0;
    float media;
    int maiorQanterior = 0, j = 0;

    printf("Insira o numero de dias\n");
    scanf("%d", &n);

    int maximosLocais[n];

    for (i = 1; i <= n; ++i) {
        printf("Insira o preço\n");
        scanf("%d", &preco);

        media += preco;
        if(i == 1){
            min = preco;
            minDia = i;
            aumentoMax = preco;
            aumentoMaxDia = i;
        }
        if(preco < min){
            min = preco;
            minDia = i;
        } else if(preco > max){
            max = preco;
            maxDia = i;
        }
        if(preco > temp){
            aumento = preco-temp;
            count++;
            maiorQanterior = 1;
            if(aumento > aumentoMax){
                aumentoMax = aumento;
                aumentoMaxDia = i;
            }
            if(count > countMax){
                countMax = count;
            }
        } else{
            count = 0;
        }
        if(maiorQanterior == 1 && preco < temp){
            maximosLocais[j] = temp;
            j++;
            maiorQanterior = 0;
        }
        temp = preco;
    }

    media /= n;

    printf("Menor - %d, Dia - %d\n", min, minDia);
    printf("Max - %d, Dia - %d\n", max, maxDia);
    printf("Media - %f\n", media);
    printf("Aumento - %d, Dia - %d\n", aumentoMax, aumentoMaxDia);
    printf("Aumentos Consecutivos - %d\n", countMax);
    for (int k = 0; k < j; ++k) {
        printf("Maximos Locais\n");
        printf("%d ", maximosLocais[k]);
    }
}

void freq2_2022_ex1(){
    int v[9] = {-40, -30, -20, -10, 0, 10, 20, 30, 40};
    int n = 9, p = 0, soma = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            for (int k = j+1; k < n; ++k) {
                soma = v[i]+v[j]+v[k];
                if(soma == p){
                    printf("(%d %d %d)\n", v[i], v[j], v[k]);
                }
            }
        }
    }
}

void freq2_2022_ex2(){
    int v[5] = {6, 2, 60, 70, 1};
    int n = 5, p = 0, soma = 0, temp;

    for (int i = n; i > 0; i--) {
        v[i] = (v[i]+v[i-1])/2;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", v[i]);
    }
}

void freq2_2022_ex3(){

    char s[100] = "pal1 pal2 jfokajfk3";
    int p = 2, c = 0;
    float soma = 0, count = 0;

    for (int i = 0; i < strlen(s); ++i) {
        if(s[i] == ' '){
            if(c >= p){
                soma += c;
                count++;
            }
            c = 0;
        } else{
            c++;
        }
    }
    if(c >= p){
        soma += c;
        count++;
    }

    printf("%.1f\n", count);
    printf("%.1f\n", soma/count);
}

void freq2_2022_ex4(){
    char s[100] = "farrrapparss";
    int p = 5, count = 0, c = 0, n = strlen(s);

    for (int i = 0; i < n; ++i) {
        if(s[i] == s[i-1]){
            for (int j = i; j < n; ++j) {
                s[j] = s[j+1];
            }
            i--;
            n--;
        }
    }

    printf("%s\n", s);
}