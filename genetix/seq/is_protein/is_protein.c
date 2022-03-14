#include <stdbool.h>
#include <string.h>

bool is_protein(char *seq) {
    int len = strlen(seq);
    int i;

    for (i = 0; i < len; ++i) {
        char base = seq[i];
        if (base != 'A' && base != 'C' && base != 'D' && base != 'E' &&
            base != 'F' && base != 'G' && base != 'H' && base != 'I' &&
            base != 'K' && base != 'L' && base != 'M' && base != 'N' &&
            base != 'P' && base != 'Q' && base != 'R' && base != 'S' &&
            base != 'T' && base != 'V' && base != 'W' && base != 'Y') {
            return false;
        }
    }

    return true;
}
