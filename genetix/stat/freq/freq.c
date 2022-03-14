#include <stdlib.h>
#include <string.h>

int *freq(char *seq) {
    int *fr = calloc(5, sizeof(int));
    int len = strlen(seq);
    int i;

    for (i = 0; i < len; i++) {
        switch (seq[i]) {
            case 'A':
                fr[0] += 1;
                break;
            case 'C':
                fr[1] += 1;
                break;
            case 'G':
                fr[2] += 1;
                break;
            case 'T':
                fr[3] += 1;
                break;
        }
    }

    return fr;
}
