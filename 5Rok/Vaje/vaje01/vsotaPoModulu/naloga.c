#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    int vsota = a + b;
    int modulo = vsota % 10;
    printf("%d\n", modulo);

    return 0;
}
