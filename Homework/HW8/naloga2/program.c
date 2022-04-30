#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool crniZmaga = false;
bool beliMoznost = false;

int min(int a, int b)
{
    return a < b ? a : b;
}

void rekurzija(int n, int k, bool poteza)
{
    if (n == 0)
    {
        if (poteza)
            crniZmaga = true;
        else
        {
            printf("ZMAGA\n");
        }
        return;
    }
    for (int i = 1; i <= min(n, k); i++)
    {
        printf("%d", i);
        rekurzija(n - i, k, !poteza);
    }
}
int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 1; i <= k; i++)
    {
        crniZmaga = false;
        rekurzija(n - i, k, false);
        printf("\n");
        // if (!crniZmaga)
        // {
        //     beliMoznost = true;
        //     int *arr = calloc(n - i, sizeof(int));
        //     printf("%d ", i);
        // }
    }
    if (!beliMoznost)
        printf("CRNI\n");
    return 0;
}
