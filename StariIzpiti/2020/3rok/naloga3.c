#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max = 0;
void funkcija()
{
    char znak = getchar();
    int counter = 0;
    bool prazno = true;
    while (znak >= 'a' && znak <= 'z')
        znak = getchar();

    if (znak == '(')
    {
        znak = getchar();
        while (znak != ')')
        {
            if (znak >= 'a' && znak <= 'z')
                funkcija();
            else if (znak == ',')
                counter++;
            prazno = false;
            znak = getchar();
        }
        if (!prazno)
            counter++;
        if (counter > max)
            max = counter;
    }
    return;
}

int main(int argc, char const *argv[])
{
    funkcija();
    printf("%d\n", max);
    return 0;
}

// vsota(f(36),g(7,zmnozek(42,0,h(),123),19)