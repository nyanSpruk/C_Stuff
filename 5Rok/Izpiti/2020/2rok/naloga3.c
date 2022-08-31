#include <stdio.h>
#include <stdbool.h>

bool fun()
{
    char c = getchar();
    if (c == 'T')
        return true;
    if (c == 'F')
        return false;
    if (c == '!')
        return !fun();

    bool a = fun();
    bool b = fun();
    if (c == '&')
        return a && b;
    if (c == '|')
        return a || b;
    return false;
}

int main(int argc, char const *argv[])
{
    printf("%c\n", fun() == true ? 'T' : 'F');
    return 0;
}
