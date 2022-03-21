#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    int correct = 1;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
        arr[i] = 0;

    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (temp >= n || arr[temp] > 0)
            correct = 0;
        arr[temp]++;
    }
    correct == 1 ? printf("DA\n") : printf("NE\n");

    return 0;
}
