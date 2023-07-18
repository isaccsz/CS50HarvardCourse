#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define tam 300

int list[tam];


void generateList();
bool binarySearch(int val);

int main(void)
{

    int val;
    generateList();

    printf("Digite o valor a se procurar na lista: ");
    scanf("%d", &val);

    if(binarySearch(val))
    {

        printf("Achei\n");

    }
    else
    {

        printf("Não existe");

    }


}

void generateList()
{

    for(int i = 0; i < tam; i++)
    {


        list[i] = i + 1;

    }

}

bool binarySearch(int val)
{

    int left = 0;
    int right = tam - 1;

    while(left <= right)
    {

        int middle = left + (right - left) / 2;

        if(middle == val)
        {

            return true;

        }
        else if( val < middle )
        {

            right = middle - 1;

        }
        else
        {

            left = middle + 1;

        }

    }

    return false;

}