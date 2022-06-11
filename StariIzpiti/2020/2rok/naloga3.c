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
}

int main(int argc, char const *argv[])
{
    printf("%s\n", fun() ? "T" : "F");
    return 0;
}
