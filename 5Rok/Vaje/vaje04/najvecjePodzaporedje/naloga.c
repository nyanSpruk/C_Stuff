#include <stdio.h>
#include <limits.h>

int main(int argc, char const *argv[])
{
    int counter = 0, n;
    scanf("%d", &n);
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int st;
        scanf("%d", &st);
        counter += st;
        if (counter <= 0)
            counter = 0;
        if (counter > max)
            max = counter;
    }
    printf("%d\n", max);
    return 0;
}