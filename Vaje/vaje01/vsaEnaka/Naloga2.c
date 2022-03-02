#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, firstNum = -1;
    scanf("%d", &n);
    bool allSame = true;
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (firstNum == -1)
        {
            firstNum = temp;
        }
        else
        {
            if (temp != firstNum)
            {
                allSame = false;
                break;
            }
        }
    }
    if (allSame)
        printf("1\n");
    else
        printf("0\n");

    return 0;
}