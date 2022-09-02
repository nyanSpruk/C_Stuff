#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int *velikosti = calloc(n + 1, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &velikosti[i]);
    }
    int counter = 0;
    for (int i = 0; i < n; i++)
    {
        bool vidiVse = true;
        for (int j = i + 1; j < n; j++)
        {
            if (velikosti[i] < velikosti[j])
            {
                vidiVse = false;
                break;
            }
        }
        if (vidiVse)
            counter++;
    }
    printf("%d\n", counter);

    return 0;
}
