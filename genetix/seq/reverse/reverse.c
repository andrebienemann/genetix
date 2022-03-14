#include <stdlib.h>
#include <string.h>

char *reverse(char *seq) {
    int len = strlen(seq);
    char *rev = malloc(len + 1);
    int i, j;

    for (i = len - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = seq[i];
    }

    rev[j] = '\0';

    return rev;
}
