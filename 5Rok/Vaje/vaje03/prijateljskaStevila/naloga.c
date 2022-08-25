#include <stdio.h>

int vsotaPravihDeliteljev(int n)
{
    int counter = 0;
    for (int i = 1; i < n; i++)
        if (n % i == 0)
            counter += i;
    return counter;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int num1 = vsotaPravihDeliteljev(n);
    int num2 = vsotaPravihDeliteljev(num1);
    if (num2 == n)
    {
        printf("%d\n", num1);
    }
    else
    {
        printf("NIMA\n");
    }
    return 0;
}