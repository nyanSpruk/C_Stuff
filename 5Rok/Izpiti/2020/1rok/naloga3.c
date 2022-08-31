#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fun(int n, int *stevila, bool *marked, int counter)
{
    if (n == counter)
    {
        // Print stevila
        bool prvi = true;
        printf("{");
        for (int i = 0; i < n; i++)
        {
            if (marked[i])
            {
                if (prvi)
                {
                    prvi = false;
                    printf("%d", stevila[i]);
                }
                else
                    printf(", %d", stevila[i]);
            }
        }
        printf("}\n");
        return;
    }
    marked[counter] = false;
    fun(n, stevila, marked, counter + 1);
    marked[counter] = true;
    fun(n, stevila, marked, counter + 1);
}

int main(int argc, char const *argv[])
{
    int n = 3;
    // scanf("%d", &n);
    int *stevila = malloc(n * sizeof(int));
    bool *s = calloc(n, sizeof(bool));
    // for (int i = 0; i < n; i++)
    // {
    //     scanf("%d", &stevila[i]);
    // }
    stevila[0] = 2;
    stevila[1] = 7;
    stevila[2] = 1;
    fun(n, stevila, s, 0);
    return 0;
}
