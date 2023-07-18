#include <stdio.h>
#include <stdlib.h>

void print_marioWorld(int i);

int main(void){

    int blocks;

    do
    {
        printf("How many blocks will be there?\n");
        scanf("%i", &blocks);

        print_marioWorld(blocks);
    }
    while(blocks<1);
}

void print_marioWorld(int numberOfBlocks)
{

    for(int i = 0; i < numberOfBlocks ; i++)
    {
        for(int j = numberOfBlocks; j >= 0; j--)
        {
            if(j>i)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }

}