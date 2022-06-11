#include <stdio.h>
#include <stdlib.h>

char tabela[500][500];

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int visina = 0;
    int maxVisina = 0;
    getchar();
    char znak;
    for (int i = 0; i < n; i++)
    {
        znak = getchar();
        if (znak == 'G')
        {
            tabela[500 - visina][i] = '/';
            visina++;
            if (visina > maxVisina)
            {
                maxVisina = visina;
            }
        }
        else if (znak == 'D')
        {
            visina--;
            tabela[500 - visina][i] = '\\';
        }
    }
    for (int i = maxVisina - 1; i >= 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (tabela[500 - i][j] == 0)
            {
                printf(".");
            }
            else
            {
                printf("%c", tabela[500 - i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}