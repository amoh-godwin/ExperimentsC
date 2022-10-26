#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>


int total_size = 0;

int file_size(char* file) {
    int size;
    int ssize;
    char c_main_str[sizeof(file) * 10];
    char* final_str = malloc(2024);
    FILE* fh;

    printf("Success\n");

    memcpy_s(c_main_str, sizeof(file) * 10, file, strlen(file));
    printf("c main str:  %s\n", c_main_str);

    char* token = strtok(c_main_str, "");
    printf("token here: %s file here: %s \n", token, c_main_str);
    snprintf(final_str, 1, "%s", "");
    while(token) {
        printf("real token %s \n", token);
        if(strcmp(final_str, "") == 0) {
            snprintf(final_str, 2024, "%s", token);
            token = NULL;
        }
        else {
            snprintf(final_str, 2024, "%s%%20%s", final_str, token);
            token = NULL;
        }
    }


    fh = fopen(final_str, "rb");

    printf("Success for file: %s\n", final_str);
    free(final_str);

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
                    printf("Total size here: %d for file\n", file_size(newfullname));
                } else {
                    get_size(newfullname);
                }
            }
        } closedir(dr);
    }
    else
        printf("Something went wrong\n");
    //free(fullname);
    free(newfullname);
    fullname = NULL;
    newfullname = NULL;

    return total_size;
}


char* replace_spaces(int a) {

    char* final_str;// = malloc(1024);
    //char c_main_str[1024];

    //memcpy_s(c_main_str, 1024, main_str, strlen(main_str));

    /*char* token = strtok(c_main_str, " ");
    printf("token here: %s \n", token);
    snprintf(final_str, 1, "%s", "");
    while(token) {
        if(strcmp(final_str, "") == 0) {
            snprintf(final_str, 1000, "%s", token);
            token = NULL;
        }
        else {
            snprintf(final_str, 1000, "%s%%20%s", final_str, token);
            puts(token);
            token = NULL;
        }
    }*/

    return final_str;

}

