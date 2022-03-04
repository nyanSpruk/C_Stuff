#include <stdio.h>

// int main()
// {
//     // Count characters in input; 1st version
//     long nCount = 0;
//     while (getchar() != EOF)
//     {
//         nCount++;
//     }

//     printf("%ld\n", nCount);

//     return 0;
// }

int main()
{
    long nCount;
    for (nCount = 0; getchar() != EOF; ++nCount)
        ;
    printf("%ld\n", nCount - 1);
    return 0;
}