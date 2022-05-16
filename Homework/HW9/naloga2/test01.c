
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

void izvedi(Tocka t, Premica p) {
    Tocka proj = projekcija(t, p);
    printf("(%d/%d, %d/%d)\n", proj.x.st, proj.x.im, proj.y.st, proj.y.im);
}

int __main__() {
    izvedi( (Tocka) {{2, 1}, {5, 1}}, (Premica) {true, {0, 1}, {-3, 1}} );
    exit(0);
    return 0;
}
