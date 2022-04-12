
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "naloga1.h"

char *zdruzi(char **nizi, char *locilo)
{
    char **p = nizi;
    char *niz = malloc(0);

    int sizeOfLocilo = strlen(locilo);
    while (*p != NULL)
    {
        int sizeOfNiz = strlen(*p);
        int sizeOfWholeNiz = strlen(niz);

        if (*(p + 1) == NULL)
        {
            niz = (char *)realloc(niz, sizeOfNiz + sizeOfWholeNiz);
            strcat(niz, *p);
        }
        else
        {
            niz = (char *)realloc(niz, sizeOfLocilo + sizeOfNiz + sizeOfWholeNiz);
            strcat(niz, *p);
            strcat(niz, locilo);
        }

        p++;
    }
    return niz;
}

// char *NIZI[] = {"", "", "", "", "", "", NULL};
// char *NIZI[] = {"", "123", "4567", "8901", "2", "34", "", "567890", NULL};

int main()
{
    // char *niz = zdruzi(NIZI, "");
    // printf("<%s>\n", niz);

    // exit(0);
    return 0;
}
