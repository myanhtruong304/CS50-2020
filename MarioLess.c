#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i;
    do
    {
        i = get_int("Size: ");
    }
    while (i < 1 || i > 8);
    
    for (int n = 0; n < i; n++)
    {
        for (int d = i-1; d > n; d--)
        {
            printf(" ");
        }
        for(int j = 0; j <= n; j++)
        {
            printf("#");
        }
         printf("\n");
     }
}
