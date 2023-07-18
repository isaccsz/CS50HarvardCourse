#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

string encryptMessage(string key, string message);

int main(int argc, string argv[])
{

    string newAlphabet, message, encryptedMessage;

    if(argc == 1)
    {

        printf("Missing argument, try rerunning like this: ./substitution (encrypting key)\n");
        return 1;

    }
    else if(argc > 2)
    {

        printf("Too much arguments, try rerunning with only one key.\n");
        return 1;

    }
    else if(strlen(argv[1]) != 26)
    {

        printf("Invalid Key. It must have 26 characters.\n");
        return 1;

    }
    else
    {

        newAlphabet = argv[1];

        for(int i = 0, n = strlen(argv[1]); i < n; i++)
        {


            if((argv[1][i] >= 'A' && argv[1][i] <= 'Z') || (argv[1][i] >= 'a' && argv[1][i] <= 'z'))
            {

                newAlphabet[i] = argv[1][i];

            }
            else
            {

                printf("Invalid Key. Only alphabet digits allowed.\n");

            }

        }

    }


    message = get_string("Digite a mensagem: ");

    encryptedMessage = encryptMessage(newAlphabet, message);


    printf("Texto cifrado: %s\n", encryptedMessage);

}


string encryptMessage(string key, string message)
{

    string doneEncrypt = message;
    int index;

    for(int i = 0, n = strlen(message); i < n; i++)
    {

        if(message[i] >= 'A' && message[i] <='Z')
        {

            index = message[i] - 65;
            doneEncrypt[i] = key[index];

        }
        else if(message[i] >= 'a' && message[i] <= 'z')
        {
            index = message[i] - 97;
            doneEncrypt[i] = key[index];
        }

    }

    return doneEncrypt;

}