#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

string encrypt(int key, string mensage);

int main(int argc, string argv[])
{

    int key;
    string encryptedMensage, mensage;

    if(argc <= 2)
    {

        if(argc == 1)
        {

            printf("Missing Argument! Rerun like this: ./caesar (key)\n");
            return 1;

        }
        else
        {

            for(int i = 0, n = strlen(argv[1]); i < n; i++){

                if(isdigit(argv[1][i]) == 0){

                    printf("Invalid argument! The argument must be a numeric key or be a positive number\n");
                    return 1;

                }

            }

            key = atoi(argv[1]);

        }
    }
    else
    {

        printf("Too much arguments! Rerun like this: ./ceasar (key)\n");
        return 1;

    }


    mensage = get_string("Digite a mensagem: ");

    encryptedMensage = encrypt(key, mensage);

    printf("%s\n", encryptedMensage);

    return 0;

}

string encrypt(int key, string mensage)
{

    int result;

    //check if key is more than 25

    if(key > 25)
    {

        while(key > 25)
        {

            key -= 25;

        }

    }


    for(int i = 0, n = strlen(mensage); i < n; i++)
    {
        if(mensage[i] >= 'A' && mensage[i] <= 'Z')
        {

            result = mensage[i] + key;

            if(result > 90){

                result -= 90;
                result += 64;

            }

            mensage[i] = result;

        }
        else if(mensage[i] >= 'a' && mensage[i] <= 'z')
        {

            result = mensage[i] + key;

            if(result > 122){

                result -= 122;
                result += 96;

            }

            mensage[i] = result;

        }
    }

    return mensage;

}