// Implements a dictionary's functionality

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 676;

//Counter of each entry in the dictionary
int counter = 0, headCounter = 0;

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int index = hash(word);
    node *linkedList = table[index];

    while (linkedList != NULL) {
        int i;
        for (i = 0; linkedList->word[i] != '\0' && toupper(linkedList->word[i]) == toupper(word[i]); i++) {
            if (linkedList->word[i] != '\0' && word[i] == '\0')
                return false; // Comprimentos diferentes, não é a mesma palavra
            else if(linkedList->word[i] == '\0' && word[i] == '\0')
                return false; // Comprimentos diferentes, não é a mesma palavra
        }

        if (linkedList->word[i] == '\0' && word[i] == '\0') {
            return true; // Encontrou a palavra na lista ligada
        }

        linkedList = linkedList->next;
    }

    return false; // Palavra não encontrada
}

// Hashes word to a number
unsigned int hash(const char *word)
{

    int index, i, j;
    i = toupper(word[0]) - 65;
    j = toupper(word[1]) - 65;
    if(j < 0)
    {
        index = i * 26;
    }
    else
    {
        index = (i * 26) + j;
    }
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
    {
        return false;
    }

    char *word = malloc(sizeof(char) * (LENGTH + 1));
    int index;
    node *inicio;
    while(fscanf(file, "%s", word) != EOF)
    {

        index = hash(word);
        if(table[index] == NULL)
        {
            table[index] = malloc(sizeof(node));
            if(table[index] == NULL)
            {
                fclose(file);
                free(word);
                return false;
            }
            table[index]->next = NULL;
            strcpy(table[index]->word, "head");
            headCounter++;

        }

        inicio = malloc(sizeof(node));
        if (inicio == NULL)
        {
            fclose(file);
            free(word);
            return false;
        }
        strcpy(inicio->word, word);
        inicio->next = table[index]->next;
        table[index]->next = inicio;
        counter++;

    }

    free(word);
    fclose(file);

    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{

    int contador = 0;

    for(int i = 0; i < N; i++)
    {

        if(table[i] != NULL)
        {

            while(table[i] != NULL)
            {

                node *tmp = table[i];
                table[i] = table[i]->next;
                free(tmp);
                contador++;

            }

        }

    }

    if(contador == counter + headCounter)
    {
        return true;
    }
    else
    {
        printf("Total de palavras no dicionario: %d\nTotal de frees: %d\n", counter, contador);
        return false;
    }


}
