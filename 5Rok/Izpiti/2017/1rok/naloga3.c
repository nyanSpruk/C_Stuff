#include <stdio.h>
#include <stdlib.h>

void fun(int vrstica, int **stevila, int koncoSt, int st)
{
    for (int i = stevila[vrstica][0]; i <= stevila[vrstica][1]; i++)
    {
        st = st * 10 + i;
        if (vrstica + 1 < stevila[vrstica][1])
        {
            fun(vrstica + 1, stevila, koncoSt, st);
            st /= 10;
        }
        else
        {
            printf("%d\n", st);
            st /= 10;
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int **tabela = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        tabela[i] = malloc(2 * sizeof(int));
        scanf("%d %d", &tabela[i][0], &tabela[i][1]);
    }
    fun(0, tabela, n, 0);
    return 0;
}
