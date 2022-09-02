#include <stdio.h>

int main(int argc, char *argv[])
{
    int n;
    scanf("%d ", &n);
    char znak;
    char prev = ' ';
    for (int i = 0; i < n; i++)
    {
        znak = getchar();
        if (prev == ' ' || (prev == '_' && (znak >= 'a' && znak <= 'z') || (znak >= 'A' && znak <= 'Z')))
        {
            if (znak >= 'a' && znak <= 'z')
            {
                int index = znak - 'a';
                putchar('A' + index);
            }
            else
                putchar(znak);
        }
        else
        {
            putchar(znak);
        }
        prev = znak;
    }
    putchar('\n');
}