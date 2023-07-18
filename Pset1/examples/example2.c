#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int x = get_int("X: ");
    int y = get_int("Y: ");

    double z = x / (double) y;

    printf("Resultado: %.2lf\n",z);

}