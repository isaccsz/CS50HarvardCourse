#include <stdlib.h>
#include<stdio.h>
#include <cs50.h>

int main(void)
{

    char *s = get_string("Digite: ");
    char *c = get_string("Digite: ");

    if(*s == *c)
    {

        printf("Truthy\n");

    }
    else
    {

        printf("Falsy\n");

    }

}