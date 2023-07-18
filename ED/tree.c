#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct no
{
    
    int key;
    struct no *left;
    struct no *right;
    int tall;
    
}no;

typedef no *structNode;

structNode tree;

void freeMemory(structNode root);
structNode createNode(structNode newNode, int key);
structNode insere(structNode folha, int key);
void printarArvore(structNode root);
void menu();

int main(void)
{
    
    tree = NULL;
    
    tree = insere(tree, 15);
    
    int opc = 0;
    
    do
    {
        
        menu();
        scanf("%d", &opc);
        
        switch(opc)
        {
            case 1:
                printf("Digite o valor: ");
                int key;
                scanf("%d", &key);
                insere(tree, key);
                break;
            case 2:
                printf("Mostrando árvore em ordem: ");
                printarArvore(tree);
                printf("\n");
                break;
            case 0:
                printf("Obrigado por utilizar a ferramenta!\n");
                freeMemory(tree);
                break;
            default:
                printf("Opção inválida. Tente novamente!\n");
        }
    }
    while(opc != 0);
    
}

structNode insere(structNode folha, int key)
{
    
    if(folha == NULL)
       return folha = createNode(folha, key);
        
    if(key > folha->key)
        folha->right = insere(folha->right, key);
    else if(key < folha->key)
        folha->left = insere(folha->left, key);
    else
        return NULL;
        
    return folha;
        
    
}

structNode createNode(structNode newNode, int key)
{
    
    newNode = (structNode) malloc(sizeof(no));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->tall = 1;
    
    return newNode;
    
}

void printarArvore(structNode root)
{
    
    if(root == NULL)
        return;
    
    printarArvore(root->left);
    printf(" %d ", root->key);
    printarArvore(root->right);
    
    
}

void menu()
{
    
    printf(" - - - - - Bem Vindo - - - - - \n");
    printf("1 - Inserir novo nó: \n");
    printf("2 - Printar nós\n");
    printf("0 - Sair\n");
    
}

void freeMemory(structNode root)
{
    
    if(root == NULL)
        return;
    
    freeMemory(root->left);
    freeMemory(root->right);
    free(root);
    
}