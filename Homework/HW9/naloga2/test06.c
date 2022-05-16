
#include <stdio.h>
#include <stdlib.h>

#include "naloga2.h"

void izvedi(Tocka t, Premica p) {
    Tocka proj = projekcija(t, p);
    printf("(%d/%d, %d/%d)\n", proj.x.st, proj.x.im, proj.y.st, proj.y.im);
}

int __main__() {
    izvedi( (Tocka) {{-3, 8}, {-9, 4}}, (Premica) {false, {-6, 7}, {-5, 2}} );
    exit(0);
    return 0;
}
