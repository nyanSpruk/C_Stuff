#include <stdio.h>

int main()
{
    int n, max = -1, second = -1;
    scanf("%d", &n);
    scanf("%d", &max);

    for (int i = 1; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp > max)
        {
            second = max;
            max = temp;
        }
        else if (temp > second && temp <= max)
            second = temp;
    }

    printf("%d\n", second);
    return 0;
}
