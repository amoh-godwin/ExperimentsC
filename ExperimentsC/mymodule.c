#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>


int total_size = 0;

int file_size(char* file) {
    int size;
    int ssize;
    FILE* fh;

    printf("Success\n");

    fh = fopen(file, "rb");

    printf("Success for file: %s\n", file);

    printf("Not null verify: %d", fh != NULL);

    if((fh != NULL)) {
        printf("Not null");
        if( fseek(fh, 0, SEEK_END)) {
            fclose(fh);
            return -1;
        }

        size = ftell(fh);
        fclose(fh);
        return size;
    }
    printf("Null I guess");
    return -1;
}

const char* fullpath(char *file1, char *file2) {

    char fullstr[1000];
    const char *fmtt = "%s/%s";
    int szz = snprintf(NULL, 0, fmtt, file1, file2);
    int bbuf[szz+1];

    printf("something\n");
    snprintf(fullstr, sizeof fullstr, fmtt, file1, file2);
    printf("this: %s\n", fullstr);
    int len = sizeof fullstr;
    char* outstring = malloc(len);

    outstring = fullstr;

    //outp = fullstr;
    //outp = "love";

    printf("out strin: %s \n", outstring);

    return outstring;
}

int not_dir(char *folder) {
    DIR *dr;

    dr = opendir(folder);
    return dr != NULL;
}

int get_size(char *foldername) {
    const char* fullname;
    char *newfullname = malloc(1000);
    DIR *dr;
    struct dirent *d;

    printf("About to open: %s\n", foldername);
    dr = opendir(foldername);
    printf("Successfully opened main folder\n");

    if (dr != NULL) {
        printf("Before for loop \n");
        for (d=readdir(dr); d != NULL; d=readdir(dr)) {

            int dot = strcmp(d->d_name, ".");
            int ddot = strcmp(d->d_name, "..");
            int dotndot = dot + ddot;

            if (dotndot > 1) {



                fullname = fullpath(foldername, d->d_name);
                printf("fullname: %s\n", fullname);
                strcpy(newfullname, fullname);

                printf("Scanned: %s d_nme: %d\n", newfullname, 0);

                if (not_dir(newfullname) < 1) {
                    total_size += file_size(newfullname);
                    printf("Total size here: %d for file\n", file_size("./testfolder/new%202.txt"));
                } else {
                    get_size(newfullname);
                }
            }
        } closedir(dr);
    }
    else
        printf("Something went wrong\n");
    free(fullname);
    free(newfullname);
    fullname = NULL;
    newfullname = NULL;

    return total_size;
}

