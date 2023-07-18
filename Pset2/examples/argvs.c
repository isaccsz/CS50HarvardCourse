#include <stdio.h>
#include <cs50.h>

int main(int argc, string argv[])
{

    if(argc == 2){
        printf("Olá %s!\n", argv[1]);
    }
    else if(argc == 3)
    {
        printf("Olá %s %s!\n", argv[1], argv[2]);
    }
    else
    {
        printf("Olá!\n");
    }

}