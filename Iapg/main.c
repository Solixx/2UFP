#include <stdio.h>

void teste_2021_ex1();

int main() {

    //teste_2021_ex1();

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