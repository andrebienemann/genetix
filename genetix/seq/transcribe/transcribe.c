#include <stdlib.h>
#include <string.h>

char *transcribe(char *seq) {
    int len = strlen(seq);
    char *rna = malloc(len + 1);
    int i;

    for (i = 0; i < len; i++) {
        rna[i] = seq[i] == 'T' ? 'U' : seq[i];
    }

    rna[i] = '\0';

    return rna;
}
