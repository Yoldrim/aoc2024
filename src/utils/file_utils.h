//
// Created by Harald Bergqvist on 2024-12-03.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long size;
    char *data;
} LoadedFile;

long file_utils_get_file_size(FILE *fptr) {
    long startingPos = ftell(fptr);
    fseek(fptr, 0L, SEEK_END);
    long pos = ftell(fptr);
    fseek(fptr, startingPos, SEEK_SET);
    return pos;
}

void file_utils_read_file(FILE *fptr, LoadedFile *file) {
    long fileSize = file_utils_get_file_size(fptr);
    file->size = fileSize;
    file->data = (char *)malloc(fileSize * sizeof(char));

    for(int i = 0; i < fileSize; i++) {
        file->data[i] = fgetc(fptr);
    }
}