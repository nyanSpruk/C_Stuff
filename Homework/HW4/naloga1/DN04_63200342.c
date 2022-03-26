#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr2[i]);
    }
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int counter = 0;
        index = 0;
        for (int j = i; j < n + 1; j++)
        {
            if (j == n)
                j = 0;
            if (arr1[j] == arr2[index])
            {
                counter++;
                index++;
                if (counter == n)
                {
                    printf("%d\n", i);
                    break;
                }
            }
            else
                break;
        }
        if (counter == n)
            break;
    }

    return 0;
}
