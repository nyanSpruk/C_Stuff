#include <stdio.h>
#include <math.h>

// int jePitagorejsko(int c)
// {
//     for (int j = 1; j < c; j++)
//     {
//         for (int k = j + 1; k < c; k++)
//         {
//             if (j * j + k * k == c * c)
//             {
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

int jePitagorejsko2(int c)
{
    for (int j = 1; j < c; j++)
    {
        int b2 = c * c - j * j;
        int b = (int)round(sqrt(b2));
        if (b * b == b2)
            return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int m, n;
    scanf("%d %d", &m, &n);
    int breakLoop = 1;
    int counter = 0;
    for (int i = m; i <= n; i++)
    {
        if (jePitagorejsko2(i))
            counter++;
    }
    printf("%d\n", counter);
    return 0;
}
