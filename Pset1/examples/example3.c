#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int counter = 0;

    counter++;
    counter--;
    counter--;

    if(counter==0)
    {
        printf("Oops!\n");
    }
    else if(counter>0)
    {
        printf("Yaaay!\n");
    }
    else
    {
        printf("Minor?!?\n");
    }

}