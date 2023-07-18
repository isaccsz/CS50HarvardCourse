#include <stdio.h>
#include <cs50.h>

int main(void)
{

    char c = get_char("Agreed? Y/N\n");

    if(c == 'y' || c == 'Y')
    {
        printf("Agreed!");
    }
    else if(c == 'n' || c == 'N')
    {
        printf("Not Agreed.");
    }

}