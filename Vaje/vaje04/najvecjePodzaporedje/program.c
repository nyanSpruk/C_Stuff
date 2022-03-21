#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);

    int max = INT_MIN;
    int vsota = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        vsota += temp;
        if (vsota > max)
            max = vsota;
        if (vsota < 0)
            vsota = 0;
    }
    printf("%d\n", max);

    return 0;
}