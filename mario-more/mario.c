#include <cs50.h>
#include <stdio.h>

void brick(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}

void space(int m)
{
    for (int i = 0; i <m; i++)
    {
        printf(" ");
    }
}

int main(void)
{
    int height = 0;
    int i = 0;
    while (height < 1 || height > 8)
    {
        height = get_int("Height: ");
    }
    /*printf("Height: %i\n", height);*/
    for (i = 0; i<height; i++)
    {
        int spaces = height-i-1;
        space(spaces);
        brick(i+1);
        printf("  ");
        brick(i+1);
        printf("\n");

        /* for (int j = 0; j<height; j++)
        {
            printf("\n");
        } */
    }
}