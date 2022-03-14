#include <string.h>

double titv_ratio(char *seq1, char *seq2) {
    int len = strlen(seq1);
    int ti = 0;
    int tv = 0;
    int i;

    for (i = 0; i < len; i++) {
        if (seq1[i] != seq2[i]) {
            if (seq1[i] == 'A' && seq2[i] == 'G') {
                ti += 1;
            } else if (seq1[i] == 'G' && seq2[i] == 'A') {
                ti += 1;
            } else if (seq1[i] == 'C' && seq2[i] == 'T') {
                ti += 1;
            } else if (seq1[i] == 'T' && seq2[i] == 'C') {
                ti += 1;
            } else {
                tv += 1;
            }
        }
    }

    if (ti == 0 || tv == 0) {
        return 0.0;
    }

    return (double)ti / tv;
}
