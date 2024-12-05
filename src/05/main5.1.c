#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/file_utils.h"
#include "../utils/string_utils.h"

int main(void) {
    // Open a file in read mode
    FILE *fptr = fopen("./src/05/test_input.txt", "r");

    // If the file exist
    if (fptr == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    LoadedFile lf;
    file_utils_read_file(fptr, &lf, 0);
    printf("File size: %ld\nFile:\"%s\"\n", lf.size, lf.data);
    char sectionOneData[21][5];
    char *sectionTwoIndex = strstr(lf.data, "\n\n");

    int row = 0;
    int column = 0;
    char *ptr = lf.data;
    while (ptr < sectionTwoIndex) {
        if (*ptr == '\n') {
            ptr++;
            row++;
            column = 0;
            continue;
        }

        sectionOneData[row][column] = *ptr;
        ptr++;
        column++;
    }


    // Close the file
    fclose(fptr);
    return 0;
}
