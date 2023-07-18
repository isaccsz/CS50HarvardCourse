#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(void)
{

    int a = 1, b = 2;

    printf("A: %d B: %d\n", a, b);

    swap(&a, &b);

    printf("A: %d B: %d\n", a, b);

}

void swap(int *a, int *b)
{

    int tmp = *a;
    *a = *b;
    *b = tmp;

}