#include <string.h>

double gc_content(char *seq) {
    int len = strlen(seq);
    double c = 0;
    int i;

    for (i = 0; i < len; i++) {
        char base = seq[i];
        if (base == 'C' || base == 'G') {
            c += 1.0;
        }
    }

    return c / len * 100;
}
