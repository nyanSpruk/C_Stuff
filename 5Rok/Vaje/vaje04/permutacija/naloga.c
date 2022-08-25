#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d\n", &n);
    int array[n + 1];
    bool answer = true;
    for (int i = 0; i < n + 1; i++)
    {
        array[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        int tempSt = -1;
        scanf("%d", &tempSt);
        if (tempSt >= n)
        {
            answer = false;
            break;
        }
        else
        {
            if (array[tempSt] > 0)
            {
                answer = false;
                break;
            }
            else
                array[tempSt]++;
        }
    }
    if (answer)
        printf("DA\n");
    else
        printf("NE\n");

    return 0;
}
