#include <stdio.h>

void strcat2(char *wordOne, char *wordTwo);

int main(int argc, char const *argv[])
{
    char s[20];
    char t[20];
    scanf("%s", s);
    scanf("%s", t);
    printf("Beseda 1 je %s in beseda 2 je %s\n", s, t);
    strcat2(s, t);
    printf("Nova beseda 1 je %s\n", s);
    return 0;
}

void strcat2(char *s, char *t)
{
    while (*s)
        s++;

    // while (*t != '\0')
    // {
    //     *s = *t;
    //     s++;
    //     t++;
    // }

    // or
    while ((*s++ = *t++))
        ;
}