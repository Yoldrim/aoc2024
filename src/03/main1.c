#include <stdio.h>
#include <string.h>

#include "../utils/file_utils.h"
#include "../utils/string_utils.h"

int main(void) {
    // Open a file in read mode
    FILE *fptr = fopen("./src/03/input1.txt", "r");

    // If the file exist
    if(fptr == NULL) {
        printf("Not able to open the file.");
        return 1;
    }

    LoadedFile lf;
    file_utils_read_file(fptr, &lf);
    printf("File size: %ld\nFile:\"%s\"\n", lf.size, lf.data);

    int agg = 0;
    const char *pos = lf.data;
    while (pos != NULL) {
        const char *c = strstr(pos, "mul(");
        char allowedCharacters[] = {'m', 'u', 'l', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ','};
        if (c != NULL) {
            int invalid = 0;
            int m[2] = {0, 0};
            int mCursor = 0;
            for (int i = 0; i < 4; i++) {
                c++;
            }
            while (*c != ')' && *c != '\0') {
                if (string_utils_is_allowed_letter(*c, allowedCharacters) == 0) {
                    printf("invalid for char: %c", *c);
                    invalid = 1;
                    break;
                }

                if (string_utils_is_ascii_number(*c)) {
                    m[mCursor] = m[mCursor] * 10 + (*c - '0');
                }

                if (*c == ',') {
                    mCursor++;
                }
                c++;
            }
            if (invalid == 0) {
                printf("Adding %i * %i to agg: %i\n", m[0], m[1], agg);
                agg += m[0] * m[1];
            }
            printf("\n");
        }
        pos = c;
    }

    printf("final agg: %i", agg);
    // Close the file
    fclose(fptr);
    return 0;
}