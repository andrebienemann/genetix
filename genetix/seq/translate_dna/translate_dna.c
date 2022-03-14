#include <stdlib.h>

#include "../transcribe/transcribe.h"
#include "../translate_rna/translate_rna.h"

char *translate_dna(char *seq) {
    char *rna = transcribe(seq);
    char *prot = translate_rna(rna);

    free(rna);

    return prot;
}
