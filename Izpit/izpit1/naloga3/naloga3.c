
/*
Ro"cno testiranje (npr. za primer test01.in):

gcc naloga3.c
./a.out < test01.in

Samodejno testiranje:

export name=naloga3
make test

Testni primeri:

test01: primer iz besedila
test02..test08: "se nekaj dodatnih testov

.in: testni vhod
.outA: pri"cakovani izhod (poljubna permutacija vrstic je tudi v redu)
.outB: pri"cakovani izhod za 0.3 to"cke (poljubna permutacija vrstic je tudi v redu)
.res: izhod va"sega programa (pri poganjanju z make)
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Lahko dodate "se kak #include, pomo"zno funkcijo ipd.z

void fun(char *S, char *niz, int *stPonovitevVsakegaZnaka, int trenutnaGlobina, int d, int n)
{
    if (trenutnaGlobina == n)
    {
        for (int i = 0; i < n; i++)
            printf("%c", niz[i]);

        printf("\n");

        return;
    }

    for (int i = 0; i < d; i++)
    {
        stPonovitevVsakegaZnaka[i]++;

        if (stPonovitevVsakegaZnaka[i] <= 3)
        {
            niz[trenutnaGlobina] = S[i];
            fun(S, niz, stPonovitevVsakegaZnaka, trenutnaGlobina + 1, d, n);
        }

        stPonovitevVsakegaZnaka[i]--;
    }
}

int main()
{
    // dopolnite ...
    int d, n;
    scanf("%d ", &d);

    char *S = (char *)malloc(d * sizeof(char));

    for (int i = 0; i < d; i++)
        scanf("%c", &S[i]);

    scanf("%d", &n);

    int *stPonovitevVsakegaZnaka = (int *)calloc(d, sizeof(int));

    char *niz = (char *)malloc(d * sizeof(char));

    fun(S, niz, stPonovitevVsakegaZnaka, 0, d, n);
    return 0;
}
