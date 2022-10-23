#include <stdio.h>
#include <stdlib.h>

int file_size(char* file) {
    int size;
    FILE* fh;

    printf("Success");

    fh = fopen(file, "rb");

    printf("Success");

    if(fh != NULL) {
        if( fseek(fh, 0, SEEK_END)) {
            fclose(fh);
            return -1;
        }

        size = ftell(fh);
        fclose(fh);
        return size;
    }
    return -1;
}

char* fullpath(char* file1, char* file2) {
    printf("Success here too");
}

