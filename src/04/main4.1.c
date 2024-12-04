#include <stdio.h>
#include <string.h>

#include "../utils/file_utils.h"

int is_xmas(char *arr, char *curr, int arrSize, int rowSize, int stepLengthX, int stepLengthY) {
    const char XMAS[] = "XMAS";
    int index = curr - arr;
    int row = index / rowSize;
    int col = index % rowSize;
    for (int i = 0; i < strlen(XMAS); i++) {
        if (i == 0 && *curr == XMAS[i]) {
            continue;
        }
        int newI = (row + i * stepLengthX) * rowSize + col + i * stepLengthY;
        if (newI < 0 || newI > arrSize) {
            return 0;
        }

        if (arr[newI] != XMAS[i]) {
            return 0;
        }
    }

    // printf("Found XMAS at row: %d col: %d\n", row, col);
    return 1;
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
    for (int i = 0; i < lf.size; i++) {
        if (lf.data[i] == '\n') {
            continue;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, 1, 0)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, 1, 1)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, 0, 1)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, -1, 1)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, -1, 0)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, -1, -1)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, 0, -1)) {
            agg++;
        }
        if (is_xmas(lf.data, lf.data + i, lf.size, rowLength, 1, -1)) {
            agg++;
        }
    }
    printf("agg: %d\n", agg);
    // Close the file
    fclose(fptr);
    return 0;
}
