#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 100

int list[tam];


void generateList();
int buscaBinaria(int arranjo[], int i, int f, int chave);

int main(void)
{

    int val;
    generateList();

    printf("Digite o valor a se procurar na lista: ");
    scanf("%d", &val);
    
    
    printf("%d\n", buscaBinaria(list, 0, tam, val));


}

void generateList()
{

    for(int i = 0; i < tam; i++)
    {


        list[i] = i + 1;

    }

}

int buscaBinaria(int arranjo[], int i, int f, int chave)
{
                if (f >= i)
                {
                               int meio = i + (f - i)/2;
                               if (arranjo[meio - 1] == chave)
                                               return meio;
                               if (arranjo[meio - 1] > chave)
                                               return buscaBinaria(arranjo, i, meio-1, chave);
                               return buscaBinaria(arranjo, meio+1, f, chave);
                }
                return -1;
}