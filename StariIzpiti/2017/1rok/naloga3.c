#include <stdio.h>
#include <stdlib.h>

void fun(int vrstica, int **stevila, int max, int st)
{
    int start = stevila[vrstica][0];
    int end = stevila[vrstica][1];
    for (int i = start; i <= end; i++)
    {
        st = st * 10 + i;
        if (vrstica + 1 < max)
        {
            fun(vrstica + 1, stevila, max, st);
            st /= 10;
        }
        else
        {
            printf("%d\n", st);
            st /= 10;
        }
    }
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int **matrika = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrika[i] = malloc(2 * sizeof(int));
        for (int j = 0; j < 2; j++)
        {
            scanf("%d", &matrika[i][j]);
        }
    }
    fun(0, matrika, n, 0);
    return 0;
}
