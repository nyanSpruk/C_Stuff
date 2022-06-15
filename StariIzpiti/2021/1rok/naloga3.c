#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* n=3
Output:
0+0+0
0+0-0
0-0+0
0-0-0
0+0+1
0+0-1
0-0+1
0-0-1
...
9+9+9
9+9-9
9-9+9
9-9-9

*/

void rekurzija(int n, int counter, bool *t, int *stevila, int ixStevil)
{
    if (counter == n)
        return;
    for (int i = 0; i <= 9; i++)
    {
        stevila[ixStevil] = i;
        for (int j = n - 1; j >= 0; j--)
        {
            printf("%d", stevila[j]);
            if (j > 0)
            {
                printf("%c", t[j] ? '+' : '-');
            }
        }
        printf("\n");
    }
    t[counter] = true;
    rekurzija(n, counter + 1, t, stevila, ixStevil - 1);
    t[counter] = false;
    rekurzija(n, counter + 1, t, stevila, ixStevil - 1);
    return;
}

int main(int argc, char const *argv[])
{
    int n;
    // scanf("%d", &n);
    n = 3;
    bool *t = malloc((n - 1) * sizeof(bool));
    int *stevila = malloc(n * sizeof(int));
    for (int i = 0; i < n - 1; i++)
    {
        t[i] = true;
    }

    rekurzija(n, 0, t, stevila, 0);
    return 0;
}
