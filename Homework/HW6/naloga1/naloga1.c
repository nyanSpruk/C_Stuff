
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char *zdruzi(char **nizi, char *locilo)
{
    char **p = nizi;
    char *niz = malloc(0);
    while (*p != NULL)
    {
        int sizeOfNiz = strlen(*p);
        int sizeOfN = strlen(niz);
        if (*(p + 1) == NULL)
        {
            niz = (char *)realloc(niz, sizeOfNiz + sizeOfN);
            strcat(niz, *p);
        }
        else
        {
            int sizeOf = strlen(locilo);
            niz = (char *)realloc(niz, sizeOf + sizeOfNiz + sizeOfN);
            strcat(niz, *p);
            strcat(niz, locilo);
        }
        p++;
    }
    return niz;
}

char *NIZI[] = {"abc", "ghi", "", NULL};

int main()
{
    char *niz = zdruzi(NIZI, "def");
    printf("<%s>\n", niz);

    exit(0);
    return 0;
}
