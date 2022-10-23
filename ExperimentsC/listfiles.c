#include <stdio.h>
#include <conio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "mymodule.h"


int main() {

    DIR *dr;
    struct dirent *d;
    char *folder_name;
    int size;

    /*char name[] = "love";
    char two[] = "..";
    /*strcat(two, "love");

    printf("%s", two);
    sprintf(name, "this %s and %s", two, two);
    printf(name);

    printf("size is %d", strlen(name));

    size = file_size("ExperimentsC.cbp");

    printf("Print size is: %d", size);*/

    printf("Which folder would you like to scan?: ");
    scanf("%s", folder_name);

    dr = opendir(folder_name);

    if (dr != NULL) {
        for (d=readdir(dr); d != NULL; d=readdir(dr)) {
            printf("%s ", d->d_name);
            printf("%d ", d->d_ino);
            printf("%d ", d->d_namlen);
            printf("rec: %d \n", d->d_reclen);
        } closedir(dr);
    }
    else
        printf("Something went wrong");
    getch();


    return 0;
}



