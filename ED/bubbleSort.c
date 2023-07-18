#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define max 100

int lista[max];

void generateNumbers();
void bubbleSort();
void troca(int* a, int *b);

int main(void)
{
    
    generateNumbers();
    
    printf("Printando lista: \n");
    for(int i = 0; i < max; i++)
    {
        
        printf(" %d ", lista[i]);
        
    }
    
    bubbleSort();
    
    printf("\nPrintando lista ordenada pelo BubbleSort: \n");
    for(int i = 0; i < max; i++)
    {
        
        printf(" %d ", lista[i]);
        
    }
    
    printf("\n");
    
}

void generateNumbers()
{
    
    
    for(int i = 0; i < max; i++)
    {
        
        lista[i] = rand() % max;
        
    }
    
}

void bubbleSort()
{
    
    int qtd = 0;
    
    for(int i = 0; i < max -1; i++)
    {
        
        for(int j = i + 1; j < max; j++)
        {
            
            if(lista[i] > lista[j])
            {
                
                troca(&lista[i], &lista[j]);
                qtd++;
                
            }
            
        }
        
        if(qtd == 0)
        {
            
            break;
            
        }
        
    }
    
    
}

void troca(int* a, int *b)
{
    
    int tmp = *a;
    
    *a = *b;
    *b = tmp;
    
}