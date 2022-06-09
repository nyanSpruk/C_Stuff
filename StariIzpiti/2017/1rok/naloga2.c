#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define maxSt 1000

void izpisiSkladisce(int **skladisce, int n, int k)
{
    for (int i = (n - 1); i >= 0; i--)
    {
        for (int j = (k - 1); j >= 0; j--)
        {
            printf("[%d][%d]", i, j);
            printf("%3d\n", skladisce[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);

    int **skladisce = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        skladisce[i] = (int *)calloc(k, sizeof(int));
    // izpisiSkladisce(skladisce, n, k);

    int t;
    scanf("%d", &t);
    int odstrani;
    int kup = 0;
    int skatla = 0;
    int stOdstranitev = 0;
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &odstrani);
        kup = odstrani / k;
        skatla = odstrani % k;
        skladisce[kup][skatla] = 1;
        // printf("odstrani: %d    kup: %d     skatla: %d\n", odstrani, kup, skatla);
        for (int visina = (k - 1); visina > skatla; visina--)
            if (skladisce[kup][visina] == 0)
                stOdstranitev++;
    }
    // izpisiSkladisce(skladisce, n, k);
    printf("%d\n", stOdstranitev);
    return 0;
}
