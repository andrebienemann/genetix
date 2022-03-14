#include <string.h>

#include "../mtable/mtable.h"

double mass(char *seq) {
    int len = strlen(seq);
    double m = 0.0;
    int i;

    for (i = 0; i < len; i++) {
        m += mtable(seq[i]);
    }

    return m;
}
