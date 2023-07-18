#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max 301

typedef struct no
{

    int value;
    struct no *next;

}no;

typedef no *query;

query lista;
int tam = 0;

void generateNumbers(query firstNode);
void printNumbers(query firstNode);
void freeMemoryAlocated(query firstNode);
void selectionSort(query firstNode);

int main(void)
{

    query firstNode;

    lista = (query) malloc(sizeof(no));
    lista->value = rand() % 100;
    lista->next = NULL;
    firstNode = lista;

    generateNumbers(firstNode);
    selectionSort(firstNode);
    printNumbers(firstNode);
    freeMemoryAlocated(firstNode);

}

void generateNumbers(query firstNode)
{
    lista = firstNode;
    int generatedNumbers[max] = {0}; // Array para armazenar os números gerados
    int index = 0;

    while (tam != max)
    {
        int randomNumber = rand() % max;

        // Verificar se o número já foi gerado anteriormente
        int repeated = 0;
        for (int i = 0; i < index; i++)
        {
            if (generatedNumbers[i] == randomNumber)
            {
                repeated = 1;
                break;
            }
        }

        if (!repeated)
        {
            generatedNumbers[index++] = randomNumber;

            if (lista->next == NULL)
            {
                lista->next = (query)malloc(sizeof(no));
                lista = lista->next;
                lista->value = randomNumber;
                tam += 1;
                lista->next = NULL;
            }
        }
    }
}

void printNumbers(query firstNode)
{

    lista = firstNode;

    while(lista->next != NULL)
    {

        printf(" %d\n", lista->value);
        lista = lista->next;

    }

    printf(" %d\n", lista->value);

}

void freeMemoryAlocated(query firstNode)
{

    lista = firstNode;

    while(lista->next != NULL)
    {

        free(lista);
        lista = lista->next;

    }

    free(lista);


}


void selectionSort(query firstNode) {
    lista = firstNode;

    while (lista != NULL) {
        query minNode = lista;
        query tempNode = lista->next;

        while (tempNode != NULL) {
            if (tempNode->value < minNode->value) {
                minNode = tempNode;
            }

            tempNode = tempNode->next;
        }

        int tempValue = lista->value;
        lista->value = minNode->value;
        minNode->value = tempValue;

        lista = lista->next;
    }
}
