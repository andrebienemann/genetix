#include <string.h>

int hamming_distance(char *seq1, char *seq2) {
    int len = strlen(seq1);
    int c = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (seq1[i] != seq2[i]) {
            c += 1;
        }
    }

    return c;
}
