#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char *delete (char *seq, char *subseq) {
    int len = strlen(seq);
    int sublen = strlen(subseq);
    char *new_seq = malloc(len + 1);
    int k = 0;
    bool skip;
    int i, j;

    for (i = 0; i < len; i++) {
        if (i + sublen - 1 < len) {
            skip = true;
            for (j = 0; j < sublen && skip; j++) {
                if (seq[i + j] != subseq[j]) {
                    skip = false;
                }
            }
            if (skip) {
                k += 1;
                i += sublen - 1;
                continue;
            }
        }
        new_seq[i - k * sublen] = seq[i];
    }

    new_seq[i - k * sublen] = '\0';

    return new_seq;
}
