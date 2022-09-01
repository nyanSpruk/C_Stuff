#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int sestEj(char *niz)
{
    char znak;
    int counter = 0;
    int index = 0;
    int tempCounter = 0;
    bool jeE = false;
    bool jeSt = false;
    bool jePod = false;
    while (niz[index] != '\0')
    {
        znak = niz[index];
        if (znak == 'E')
        {
            jeE = true;
            jeSt = false;
            jePod = false;
        }
        else if (jeE && (znak >= '1' && znak <= '9'))
        {
            tempCounter = tempCounter * 10 + (znak - '0');
            jeSt = true;
        }
        else if (jeSt && jeE && (znak >= '0' && znak <= '9'))
        {
            tempCounter = tempCounter * 10 + (znak - '0');
        }
        else if (znak == '_' && jeSt && jeE)
        {
            jeE = false;
            jeSt = false;
            jePod = false;
            if (tempCounter >= 100 && tempCounter <= 999)
            {
                printf("%d\n", tempCounter);
                counter += tempCounter;
            }
            tempCounter = 0;
        }
        else
        {
            jeE = false;
            jeSt = false;
            jePod = false;
            tempCounter = 0;
        }

        // printf("%c", niz[index]);
        index++;
    }
    return counter;
}

int main(int argc, char const *argv[])
{
    char *niz = "543_E123_e456_E75_E900/E7.4_E825.3_E0357_E089_E_EE651_abcdE736_E842";
    int result = sestEj(niz);
    printf("%d\n", result);
    return 0;
}
