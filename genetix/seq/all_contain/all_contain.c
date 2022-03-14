#include <stdbool.h>
#include <string.h>

bool all_contain(char **arr, int size, char *sub) {
    int i;

    for (i = 0; i < size; i++) {
        if (strstr(arr[i], sub) == NULL) {
            return false;
        }
    }

    return true;
}
