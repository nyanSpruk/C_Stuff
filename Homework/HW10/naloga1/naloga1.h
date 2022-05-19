
typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* zdesetkaj(Vozlisce* zacetek, int k);
