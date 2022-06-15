#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d ", &n);
    char znak, prev;
    for (int i = 0; i < n; i++)
    {
        znak = getchar();
        if (znak >= 'a' && znak <= 'z' && i == 0)
            putchar(znak - 32);
        else if (prev == '_' && znak >= 'a' && znak <= 'z')
            putchar(znak - 32);
        else
            putchar(znak);
        prev = znak;
    }
    putchar('\n');
    return 0;
}
