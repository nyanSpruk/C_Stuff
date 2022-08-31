#include <stdio.h>
#include <stdbool.h>

int max = 0;
void fun()
{
    char c = getchar();
    int counter = 0;
    bool prazno = true;
    while (c >= 'a' && c <= 'z')
        c = getchar();

    if (c == '(')
    {
        c = getchar();
        while (c != ')')
        {

            if (c >= 'a' && c <= 'z')
                fun();
            else if (c == ',')
                counter++;
            prazno = false;
            c = getchar();
        }
        if (!prazno)
            counter++;
        if (counter > max)
            max = counter;
    }
}

int main(int argc, char const *argv[])
{
    fun();
    printf("%d\n", max);
    return 0;
}

// vsota(f(36),g(7,zmnozek(42,0,h(),123),19))
// vsota()