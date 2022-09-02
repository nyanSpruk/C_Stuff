#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fun(int n, int stSt, char *out, bool znak, int counterZnakov)
{
    if (n == stSt)
    {
        printf("%s\n", out);
        return;
    }
    if (znak)
    {
        out[counterZnakov] = '+';
        fun(n, stSt, out, false, counterZnakov + 1);
        out[counterZnakov] = '-';
        fun(n, stSt, out, false, counterZnakov + 1);
    }
    else
    {
        for (int i = 0; i <= 9; i++)
        {
            out[counterZnakov] = '0' + i;
            fun(n, stSt + 1, out, true, counterZnakov + 1);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    // int n = 3;
    char *out = calloc(2 * n - 1, sizeof(char));
    fun(n, 0, out, false, 0);
    return 0;
}
