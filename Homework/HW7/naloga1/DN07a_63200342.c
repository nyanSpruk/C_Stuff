#include <stdio.h>
#include <stdlib.h>
int maxDepth;

void fun(int **values, int stNivojev, int elIndex, int dolzinaArr)
{
    if (elIndex >= dolzinaArr || elIndex < 0 || (values[0][elIndex] == 0 && values[1][elIndex] == 0))
    {
        maxDepth = stNivojev > maxDepth ? stNivojev : maxDepth;
        return;
    }

    if (values[0][elIndex] != 0)
        fun(values, stNivojev + 1, elIndex + values[0][elIndex], dolzinaArr);
    if (values[1][elIndex] != 0)
        fun(values, stNivojev + 1, elIndex + values[1][elIndex], dolzinaArr);
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int **tabeli = calloc(2, sizeof(int *));
    tabeli[0] = calloc(n, sizeof(int));
    tabeli[1] = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d %d", &tabeli[0][i], &tabeli[1][i]);

    fun(tabeli, 0, 0, n);
    printf("%d\n", maxDepth);
    return 0;
}
