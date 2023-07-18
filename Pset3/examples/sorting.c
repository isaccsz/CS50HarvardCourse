#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{

    int list[] = {8, 4, 2, 5, 6, 1, 7, 3};

    int smallest,index;

    for(int i = 0; i < 7; i++)
    {

        smallest = list[i];

        for(int j = i + 1; j < 8; j++)
        {


            if(list[j] < smallest)
            {

                smallest = list[j];
                index = j;

            }

        }


        list[index] = list[i];
        list[i] = smallest;

        printf("Nova array: \n");
        for(int k = 0; k <8; k++)
        {

            printf("%i ",list[k]);

        }
        printf("\n");

    }

    for(int i = 0; i <8; i++)
    {

        printf("%i ",list[i]);

    }

    printf("\n");

}