#include <stdlib.h>
#include <string.h>

#include "../ctable/ctable.h"

char *translate_rna(char *seq) {
    int len = strlen(seq) / 3;
    char *prot = malloc(len + 1);
    char trpl[3];
    int i;

    for (i = 0; i < len; i++) {
        memcpy(trpl, &seq[i * 3], 3);
        prot[i] = ctable(trpl);
    }

    prot[i] = '\0';

    return prot;
}
