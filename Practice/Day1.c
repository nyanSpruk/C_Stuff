#include <stdio.h>

int main()
{
    int a, b;
    printf("Input first number.\n");
    scanf("%d", &a);
    printf("Input second number.\n");
    scanf("%d", &b);
    int result = a + b;
    printf("Your number is %d.\n", result);
    return 0;
}