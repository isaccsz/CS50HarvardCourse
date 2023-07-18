#include <stdio.h>
#include <cs50.h>

int main(void)
{

    double value = get_double("Digite o valor: ");
    double result = value;
    int coins=0;

    while (true)
    {

        if(result-0.25>=0)
        {

            result-=0.25;
            coins++;

        }else if(result-0.10>=0){

            result-=0.10;
            coins++;

        }else if(result-0.05>=0){

            result-=0.05;
            coins++;

        }else if(result-0.01>=0){

            result-=0.01;
            coins++;

        }else{
            break;
        }


    }

    printf("%i\n",coins);

}