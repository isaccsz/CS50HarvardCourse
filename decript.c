#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char palavra[100];
    printf("Digite a string: ");
    fgets(palavra, sizeof(palavra), stdin);

    int i = 0;
    int deslocamento = 16;

    while (palavra[i] != '\0')
    {
        if (palavra[i] >= 'a' && palavra[i] <= 'z')
        {
            palavra[i] = (palavra[i] - 'a' + deslocamento) % 26 + 'a';
        }
        else if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            palavra[i] = (palavra[i] - 'A' + deslocamento) % 26 + 'A';
        }
        i++;
    }

    printf("Nova palavra: %s\n", palavra);

    return 0;
}