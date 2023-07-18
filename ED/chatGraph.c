#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define tam 10

int grafo[tam][tam];
int number;

bool construirMatriz();
void printarGrafo();
bool inserirAresta();
bool removerAresta();
void menu();
void BFS(int inicio);

int main(void)
{
    int choose = 1;

    do
    {
        printf("Digite o número de vértices: ");
        scanf("%d", &number);
    }
    while (!construirMatriz());

    while (choose != 0)
    {
        menu();
        scanf("%d", &choose);

        switch (choose)
        {
            case 1:
                inserirAresta();
                break;
            case 2:
                removerAresta();
                break;
            case 3:
                printarGrafo();
                break;
            case 4:
                printf("Digite o vértice de início da busca: ");
                int inicio;
                scanf("%d", &inicio);
                BFS(inicio);
                break;
            case 0:
                printf("Obrigado por usar a ferramenta!\n");
                break;
            default:
                printf("Opção Inválida\n");
        }
    }
}

void printarGrafo()
{
    printf(" ");

    for (int i = 0; i < number; i++)
    {
        printf(" %c ", 'a' + i);
    }

    printf("\n");

    for (int i = 0; i < number; i++)
    {
        printf("%c", 'a' + i);

        for (int j = 0; j < number; j++)
        {
            printf(" %d ", grafo[i][j]);
        }

        printf("\n");
    }
}

bool construirMatriz()
{
    if (number <= 1 || number >= tam)
    {
        printf("Impossível construir grafo\n");
        return false;
    }

    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < number; j++)
        {
            grafo[i][j] = 0;
        }
    }

    return true;
}

bool inserirAresta()
{
    char x, y;
    int conversionX, conversionY;

    printf("Vértices do Grafo: \n");
    for (int i = 0; i < number; i++)
    {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    printf("Digite o primeiro vértice: ");
    scanf(" %c", &x);

    printf("Digite o segundo vértice: ");
    scanf(" %c", &y);

    if (x == y)
    {
        printf("Impossível criar aresta com um único vértice\n");
        return false;
    }
    else if (x - 'a' < 0 || x - 'a' >= tam)
    {
        printf("Entradas inválidas para criar vértice\n");
        return false;
    }

    conversionX = (int)x - 'a';
    conversionY = (int)y - 'a';

    grafo[conversionX][conversionY] = 1;
    grafo[conversionY][conversionX] = 1;

    return true;
}

bool removerAresta()
{
    char x, y;
    int conversionX, conversionY;

    printf("Vértices do Grafo: \n");
    for (int i = 0; i < number; i++)
    {
        printf("%c ", 'a' + i);
    }
    printf("\n");

    printf("Digite o primeiro vértice: ");
    scanf(" %c", &x);

    printf("Digite o segundo vértice: ");
    scanf(" %c", &y);

    if (x == y)
    {
        printf("Impossível criar aresta com um único vértice\n");
        return false;
    }
    else if (x - 'a' < 0 || x - 'a' >= tam)
    {
        printf("Entradas inválidas para criar vértice\n");
        return false;
    }

    conversionX = (int)x - 'a';
    conversionY = (int)y - 'a';

    if (grafo[conversionX][conversionY] == 0 && grafo[conversionY][conversionX] == 0)
    {
        printf("Aresta inexistente\n");
        return false;
    }

    grafo[conversionX][conversionY] = 0;
    grafo[conversionY][conversionX] = 0;

    return true;
}

void BFS(int inicio)
{
    bool visitado[number];
    for (int i = 0; i < number; i++)
    {
        visitado[i] = false;
    }

    int fila[number];
    int frente = 0;
    int tras = 0;
    
    visitado[inicio] = true;
    fila[tras++] = inicio;

    printf("BFS a partir do vértice %c: ", 'a' + inicio);

    while (frente != tras)
    {
        int verticeAtual = fila[frente++];
        printf("%c ", 'a' + verticeAtual);

        for (int i = 0; i < number; i++)
        {
            if (grafo[verticeAtual][i] == 1 && !visitado[i])
            {
                visitado[i] = true;
                fila[tras++] = i;
            }
        }
    }

    printf("\n");
}

void menu()
{
    printf(" - - - Bem Vindo - - - \n");
    printf("Escolha uma das opções abaixo: \n");
    printf("1 - Inserir aresta\n");
    printf("2 - Remover aresta\n");
    printf("3 - Mostrar Matriz adjacente\n");
    printf("4 - BFS (Busca em Largura)\n");
    printf("0 - Sair\n");
}