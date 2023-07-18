#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <ctype.h>
#include <locale.h>

int main(void)
{

    setlocale(LC_ALL, "portuguese");
    char *nome = malloc(21);

    printf("Digite o nome: ");
    fgets(nome, 20, stdin);

    for(int i = 0; i < 20; i++)
    {

        if(nome[i] == '\n')
        {
            nome[i] = '\0';
            break;
        }
        else if(nome[i] == ' ')
        {

            nome[i] = 'i' + i;

        }

        nome[i] = toupper(nome[i]);
        nome[i] = nome[i] + 1;
        //criptografando


    }

    printf("%s\n", nome);

    free(nome);

}