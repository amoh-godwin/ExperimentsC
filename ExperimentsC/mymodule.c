#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

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

char (*fullpath(char *file1, char *file2)) {
    char fullstr[1000];
    char (*outp);

    sprintf(fullstr, "%s/%s", file1, file2);
    printf("this: %s", fullstr);

    outp = &fullstr;

    return outp;
}

int is_dir(char *folder) {
    DIR *dr;

    dr = opendir(folder);
    if(dr != NULL) {
        return 0;
    } else {
        return 1;
    }
}

