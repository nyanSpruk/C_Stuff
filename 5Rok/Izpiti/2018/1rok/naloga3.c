#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int min = INT_MAX;

void fun(int *stevila, int stStevil, int index, int vsota1, int vsota2)
{
    if (stStevil == index)
    {
        if (abs(vsota1 - vsota2) < min)
            min = abs(vsota1 - vsota2);
        return;
    }
    fun(stevila, stStevil, index + 1, vsota1 + stevila[index], vsota2);
    fun(stevila, stStevil, index + 1, vsota1, vsota2 + stevila[index]);
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

    fun(stevila, n, 0, 0, 0);
    printf("%d\n", min);
    return 0;
}
