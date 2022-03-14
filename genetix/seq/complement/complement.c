#include <stdlib.h>
#include <string.h>

#include "../cbase/cbase.h"

char *complement(char *seq) {
    int len = strlen(seq);
    char *cmpl = malloc(len + 1);
    int i;

    for (i = 0; i < len; i++) {
        cmpl[i] = cbase(seq[i]);
    }

    cmpl[i] = '\0';

    return cmpl;
}
