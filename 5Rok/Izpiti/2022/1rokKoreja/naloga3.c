#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void fun(char *S, char *niz, int *stPonovitevVsakegaZnaka, int trenutnaGlobina, int d, int n)
{
    if (trenutnaGlobina == n)
    {
        for (int i = 0; i < n; i++)
            printf("%c", niz[i]);
        printf("\n");
        return;
    }
    for (int i = 0; i < d; i++)
    {
        stPonovitevVsakegaZnaka[i]++;
        if (stPonovitevVsakegaZnaka[i] <= 3)
        {
            niz[trenutnaGlobina] = S[i];
            fun(S, niz, stPonovitevVsakegaZnaka, trenutnaGlobina + 1, d, n);
        }
        stPonovitevVsakegaZnaka[i]--;
    }
}

int main(int argc, char const *argv[])
{
    int d, n;
    scanf("%d ", &d);

    char *S = (char *)malloc(d * sizeof(char));

    for (int i = 0; i < d; i++)
        scanf("%c", &S[i]);

    scanf("%d", &n);

    int *stPonovitevVsakegaZnaka = (int *)calloc(d, sizeof(int));

    char *niz = (char *)malloc(d * sizeof(char));

    fun(S, niz, stPonovitevVsakegaZnaka, 0, d, n);
    return 0;
}
