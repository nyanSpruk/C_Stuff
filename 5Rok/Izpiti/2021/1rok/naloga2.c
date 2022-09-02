#include <stdio.h>
#include <stdlib.h>

typedef struct _Vozlisce
{
    struct _Vozlisce *n; // naslednje vozlišče v verigi oz. NULL, če ga ni
} Vozlisce;
int dolzina(Vozlisce *start)
{
    int counter = 0;
    Vozlisce *v = start;
    while (v != NULL)
    {
        counter++;
        v = v->n;
    }
    return counter;
}

Vozlisce *sticisce(Vozlisce *a, Vozlisce *b)
{
    int dolzinaA = dolzina(a);
    int dolzinaB = dolzina(b);
    if (dolzinaA > dolzinaB)
    {
        int razlika = dolzinaA - dolzinaB;
        for (int i = 0; i < razlika; i++)
        {
            vozlisceA = vozlisceA.n;
        }
    }
    else if (dolzinaA < dolzinaB)
    {
        int razlika = dolzinaB - dolzinaA;
        for (int i = 0; i < razlika; i++)
        {
            vozlisceB = vozlisceB.n;
        }
    }
    while (vozlisceA != vozlisceB)
    {
        vozlisceA = vozlisceA.n;
        vozlisceB = vozlisceB.n;
    }
    return vozlisceA;
}

int main(int argc, char const *argv[])
{
    Vozlisce *sticisce = sticisce(a, b);

    return 0;
}