#include <stdlib.h>
#include <string.h>

char *transcribe_back(char *seq) {
    int len = strlen(seq);
    char *dna = malloc(len + 1);
    int i;

    for (i = 0; i < len; ++i) {
        dna[i] = seq[i] == 'U' ? 'T' : seq[i];
    }

    dna[i] = '\0';

    return dna;
}
