#include <stdlib.h>

#include "../complement/complement.h"
#include "../reverse/reverse.h"

char *reverse_complement(char *seq) {
    char *cmp = complement(seq);
    char *revcmp = reverse(cmp);

    free(cmp);

    return revcmp;
}
