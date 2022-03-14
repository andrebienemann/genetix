#include <stdlib.h>
#include <string.h>

int *shortest_seq(char **arr, int size) {
    int *s = malloc(2 * sizeof(int));

    s[0] = 0;
    s[1] = strlen(arr[0]);

    int i, l;

    for (i = 1; i < size; i++) {
        l = strlen(arr[i]);
        if (l < s[1]) {
            s[0] = i;
            s[1] = l;
        }
    }

    return s;
}
