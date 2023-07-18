#include<stdio.h>
#include<cs50.h>

int main(void)
{

    int popInitial, popFinal, years = 0;

    // TODO: Solicite o valor inicial ao usuário
    do
    {
        popInitial = get_int("Start Size: ");
    }
    while(popInitial<9);

    // TODO: Solicite o valor final ao usuário
    do
    {

        popFinal = get_int("End Size: ");

    }
    while(popFinal<popInitial);

    // TODO: Calcule o número de anos até o limite
    while(popInitial<popFinal)
    {

        popInitial += (popInitial/3)-(popInitial/4);

        years += 1;

    }

    // TODO: Imprima o número de anos
    printf("Years: %i\n", years);

}