#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b) {
    return a > b ? b : a;
}

// zmaga crni --> false, zmaga beli --> true
bool rekurzija(int n, int k, bool poteza) {
    if (n <= k) 
        return poteza;

    bool zmagaBeli;
    if (poteza) { 
        // beli na potezi
        zmagaBeli = false;
        for (int i = 1; i <= k; i++)
            zmagaBeli = zmagaBeli | rekurzija(n-i, k, false); // beli mora zmagati pri eni ali vec moznosti
    }
    else { 
        // crni na potezi
        zmagaBeli = true;
        for (int i = 1; i <= k; i++)
            zmagaBeli = zmagaBeli & rekurzija(n-i, k, true); // beli mora zmagati pri vseh moznostih crnega
    }
    return zmagaBeli;
}

void izrisiRekurzivno(int ostanek, int k, int x, int* poteze , int indeksPoteze) {
    // printf("Rekurzija\n");
    // printf("Ostenk = %d, x = %d, ineksPoteze = %d\n", ostanek, x, indeksPoteze);
    if (ostanek == 0) {
        printf("%d", poteze[0]);
        for (int i = 1; i < indeksPoteze; i+=2) {
            printf(" -> [%d] -> %d", poteze[i], poteze[i+1]);
        }
        printf("\n");
    }
    else if (x == 0) {
        // printf("X=0: Ostenk = %d, x = %d, ineksPoteze = %d\n", ostanek, x, indeksPoteze);
        for (int i = 1; i <= k; i++) {
            poteze[indeksPoteze] = i;
            izrisiRekurzivno(ostanek - i, k, k-i+1, poteze, indeksPoteze+1);
        }
    }
    else {
        // printf("X!=0: Ostenk = %d, x = %d, ineksPoteze = %d\n", ostanek, x, indeksPoteze);
        poteze[indeksPoteze] = x;
        izrisiRekurzivno(ostanek - x, k, 0, poteze, indeksPoteze+1);
    }
}

int main()
{   
    int n; scanf("%d",&n);
    int k; scanf("%d",&k);
    bool zmagaCrni = true;
    int* poteze = malloc(sizeof(int) * n);
    for (int i = 1; i <= min(k,n); i++) {
        if (rekurzija(n-i,k,false)) {
            poteze[0] = i;
            izrisiRekurzivno(n-i, k, 0, poteze, 1);
            zmagaCrni = false;
        }
    }
    free(poteze);
    if (zmagaCrni) printf("CRNI\n");
    return 0;
}