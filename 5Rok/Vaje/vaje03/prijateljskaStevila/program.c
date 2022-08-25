#include <stdio.h>

int vsotaPravihDel(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
        if (n % i == 0)
            sum += i;
    return sum;
}

int main(int argc, char const *argv[])
{
    int number;
    scanf("%d", &number);
    int a = vsotaPravihDel(number);
    if (number == vsotaPravihDel(a))
        printf("%d\n", a);
    else
        printf("NIMA\n");
    return 0;
}
