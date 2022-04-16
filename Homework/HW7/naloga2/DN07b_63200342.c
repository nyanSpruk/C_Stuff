#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void fun(char **strings, int currVrstica, int vrstica, char *tempString)
{
    if (currVrstica == vrstica)
    {
        printf("%s\n", tempString);
        return;
    }

    for (int i = 0; i < strlen(*(strings + currVrstica)); i++)
    {
        tempString[currVrstica] = strings[currVrstica][i];
        fun(strings, currVrstica + 1, vrstica, tempString);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    char **strings = calloc(n, sizeof(char *));

    for (int i = 0; i < n; i++)
    {
        strings[i] = calloc(43, sizeof(char));
        scanf("%s", strings[i]);
    }
    char *beseda = calloc(43, sizeof(char));
    fun(strings, 0, n, beseda);

    free(beseda);
    for (int i = 0; i < n; i++)
        free(strings[i]);

    free(strings);
    return 0;
}
