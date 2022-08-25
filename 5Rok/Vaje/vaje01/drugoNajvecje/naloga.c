#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int max, secondMax;
    scanf("%d %d", &max, &secondMax);
    if (secondMax > max)
    {
        int temp = secondMax;
        secondMax = max;
        max = temp;
    }
    for (int i = 0; i < n - 2; i++)
    {
        int stevilo;
        scanf("%d", &stevilo);
        if (stevilo > max)
        {
            secondMax = max;
            max = stevilo;
        }
        else if (stevilo > secondMax)
        {
            secondMax = stevilo;
        }
    }
    printf("%d\n", secondMax);
    return 0;
}
