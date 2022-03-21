#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int vsota = 0;
    int max = 0;
    max = arr[0];
    for (int i = 0; i < n; i++)
    {
        vsota = 0;
        for (int j = i; j < n; j++)
        {
            vsota += arr[j];
            if (vsota > max)
                max = vsota;
        }
    }
    printf("%d\n", max);

    return 0;
}