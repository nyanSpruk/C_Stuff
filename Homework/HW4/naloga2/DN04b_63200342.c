#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int n, k;
    scanf("%d%d", &n, &k);

    long counter = 0;
    int *arr = (int *)calloc(k, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[temp]++;
    }

    for (int i = 1; i < k; i++)
    {
        if (i > k / 2)
            break;

        counter += (long)arr[i] * (long)arr[k - i];
    }
    if (k % 2 == 0 && arr[k / 2] >= 2)
    {
        counter -= (arr[k / 2] * arr[k / 2] + arr[k / 2]) / 2;
    }

    printf("%ld\n", counter);
    return 0;
}
