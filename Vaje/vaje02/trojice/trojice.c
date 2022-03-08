#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// bool jePitagorejska(int c)
// {
//     for (int i = 1; i < c; i++)
//     {
//         for (int j = i + 1; j < c; j++)
//         {
//             if (i * i + j * j == c * c)
//             {
//                 // printf("Prvo=%d, drugo=%d in result=%d\n", i, j, k);
//                 return true;
//             }
//         }
//     }
// }

bool jePitagorejska(int c)
{
    for (int i = 1; i < c; i++)
    {
        int b2 = c * c - i * i;
        int b = (int)round(sqrt(b2));
        if (b * b == b2)
            return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    int n, m;
    int counter = 0;
    scanf("%d %d", &n, &m);
    for (int k = n; k <= m; k++)
    {
        if (jePitagorejska(k))
            counter++;
    }
    printf("%d\n", counter);
    return 0;
}
