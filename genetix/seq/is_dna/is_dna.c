#include <stdbool.h>
#include <string.h>

bool is_dna(char *seq) {
    int len = strlen(seq);
    int i;

    for (i = 0; i < len; ++i) {
        char base = seq[i];
        if (base != 'A' && base != 'C' && base != 'G' && base != 'T') {
            return false;
        }
    }

    return true;
}
