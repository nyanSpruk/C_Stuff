#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    char str[1001];
    scanf("%s", str);
    // char str[6] = "123456";
    int dolzina = strlen(str);
    int stBrezPike = dolzina % 3;
    bool ostanek = stBrezPike > 0 ? true : false;
    printf("%d\n", dolzina);
    if (dolzina < 4)
        printf("%s\n", str);
    else
    {
        for (int i = 0; i < dolzina; i++)
        {
            if (!ostanek)
            {
                if (i > 0 && i % 3 == 0)
                    printf(".%c", str[i]);
                else
                    printf("%c", str[i]);
            }
            else
            {
                if (stBrezPike > 0)
                {
                    stBrezPike--;
                    printf("%c", str[i]);
                }
                else
                {
                    if (dolzina % 3 == 2)
                    {

                        if ((i + (dolzina % 3) - 1) % 3 == 0)
                        {
                            printf(".%c", str[i]);
                        }
                        else
                        {
                            printf("%c", str[i]);
                        }
                    }
                    else if (dolzina % 3 == 1)
                    {
                        if ((i + (dolzina % 3) + 1) % 3 == 0)
                        {
                            printf(".%c", str[i]);
                        }
                        else
                        {
                            printf("%c", str[i]);
                        }
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}