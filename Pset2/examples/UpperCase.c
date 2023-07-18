#include <stdio.h>
#include <ctype.h>
#include <cs50.h>
#include <string.h>

int main(void)
{

    string name = get_string("Digite seu nome: ");

    for( int i = 0, n = strlen(name); i<n ; i++)
    {

        if(islower(name[i]))
        {
            printf("%c", toupper(name[i]));
        }
        else
        {
            printf("%c", name[i]);
        }

    }

    printf("\n");

}