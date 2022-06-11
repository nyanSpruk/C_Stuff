#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void funkcija(int n, int counter, int *stevila, bool *t)
{
    if (counter == n)
    {
        bool prvi = true;
        printf("{");
        for (int i = 0; i < counter; i++)
        {
            if (t[i])
            {
                if (prvi)
                {
                    printf("%d", stevila[i]);
                    prvi = false;
                }
                else
                {
                    printf(", %d", stevila[i]);
                }
            }
        }
        printf("}\n");
        return;
    }
    t[counter] = true;
    funkcija(n, counter + 1, stevila, t);
    t[counter] = false;
    funkcija(n, counter + 1, stevila, t);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *stevila = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &stevila[i]);
    }
    bool *t = malloc(n * sizeof(bool));
    funkcija(n, 0, stevila, t);
    return 0;
}
