#include <stdio.h>

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    int prejsni = -1;
    int output = 1;
    for (int i = 0; i < n; i++)
    {
        int stevilo = -1;
        scanf("%d", &stevilo);
        if (prejsni != -1)
        {
            if (stevilo != prejsni)
            {
                output = 0;
                break;
            }
        }
        prejsni = stevilo;
    }
    printf("%d\n", output);
    return 0;
}
