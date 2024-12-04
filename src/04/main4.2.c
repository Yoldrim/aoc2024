#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/file_utils.h"
#include "../utils/string_utils.h"

typedef struct {
    int x;
    int y;
} Coordinates;

int twoD_to_oneD(int x, int y, int rowSize) {
    return x * rowSize + y;
}

void *oneD_to_twoD(int x, int rowSize, Coordinates *out) {
    out->x = x / rowSize;
    out->y = x % rowSize;
}

int exists_in_array(int x, int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    // Open a file in read mode
    FILE *fptr = fopen("./src/04/input1.txt", "r");

    // If the file exist
    if (fptr == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    LoadedFile lf;
    file_utils_read_file(fptr, &lf, 0);
    printf("File size: %ld\nFile:\"%s\"\n", lf.size, lf.data);


    const char *c = strstr(lf.data, "\n");
    int rowLength = c - lf.data + 1;
    printf("rowLength: %d\n", rowLength);
    int agg = 0;

    int *mIndices = malloc(65565 * sizeof(int));
    size_t mIndicesSize = string_utils_find_all_indices(lf.data, "M", mIndices);

    int *aIndices = malloc(65565 * sizeof(int));
    size_t aIndicesSize = string_utils_find_all_indices(lf.data, "A", aIndices);

    int *sIndices = malloc(65565 * sizeof(int));
    size_t sIndicesSize = string_utils_find_all_indices(lf.data, "S", sIndices);

    for (int i = 0; i < lf.size - 3; i++) {
        Coordinates *coords = malloc(sizeof(Coordinates));
        oneD_to_twoD(i, rowLength, coords);
        if (!exists_in_array(twoD_to_oneD(coords->x + 1, coords->y + 1, rowLength), aIndices, aIndicesSize)) {
            free(coords);
            coords = NULL;
            continue;
        }

        if (!((exists_in_array(twoD_to_oneD(coords->x, coords->y, rowLength), mIndices, mIndicesSize) &&
               exists_in_array(twoD_to_oneD(coords->x + 2, coords->y + 2, rowLength), sIndices, sIndicesSize)) ||
              (exists_in_array(twoD_to_oneD(coords->x, coords->y, rowLength), sIndices, sIndicesSize) &&
               exists_in_array(twoD_to_oneD(coords->x + 2, coords->y + 2, rowLength), mIndices, mIndicesSize)))) {
            free(coords);
            coords = NULL;
            continue;
        }

        if (!((exists_in_array(twoD_to_oneD(coords->x + 2, coords->y, rowLength), mIndices, mIndicesSize) &&
               exists_in_array(twoD_to_oneD(coords->x, coords->y + 2, rowLength), sIndices, sIndicesSize)) ||
              (exists_in_array(twoD_to_oneD(coords->x + 2, coords->y, rowLength), sIndices, sIndicesSize) &&
               exists_in_array(twoD_to_oneD(coords->x, coords->y + 2, rowLength), mIndices, mIndicesSize)))) {
            free(coords);
            coords = NULL;
            continue;
        }
        agg++;

        free(coords);
        coords = NULL;
    }


    printf("agg: %d\n", agg);
    // Close the file
    fclose(fptr);
    free(mIndices);
    free(aIndices);
    free(sIndices);
    return 0;
}
