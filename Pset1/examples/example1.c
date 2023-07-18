#include <stdio.h>
#include <cs50.h>

int main(void)
{

    long x = get_long("x: ");

    long y = get_long("y: ");

    printf("Soma X+Y: %li\n", x + y);

}