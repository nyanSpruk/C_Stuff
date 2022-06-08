#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *visine = calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &visine[i]);
    }

    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        bool pass = true;
        int oseba = visine[i];
        // int najvisja = visine[i];
        for (int j = i + 1; j <= n; j++)
        {
            if (visine[j] > oseba)
            {
                pass = false;
                break;
            }
        }
        if (pass)
        {
            counter++;
        }
    }
    free(visine);
    printf("%d\n", counter);
    return 0;
}
