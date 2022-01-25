#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Height: ");
    } while (n > 8 || n < 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            printf(" ");
        }
        for (int k = n - i; k < n + 1; k++)
        {
            printf("#");
        }
        printf("  ");
        for (int f = n - i; f < n + 1; f++)
        {
            printf("#");
        }
        printf("\n");
    }
}
