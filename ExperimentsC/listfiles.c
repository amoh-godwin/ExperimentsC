#include <stdio.h>
#include <conio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>

#include "mymodule.h"


int main() {

    char folder_name[1000];
    int size;

    /*strcat(two, "love");

    printf("%s", two);
    sprintf(name, "this %s and %s", two, two);
    printf(name);

    printf("size is %d", strlen(name));

    size = file_size("ExperimentsC.cbp");

    printf("Print size is: %d", size);*/


    printf("Which folder would you like to scan?: \n");
    scanf("%s", &folder_name);

    printf("This is the folder: %s\n", folder_name);

    printf("done\n");

    size = get_size(folder_name);

    printf("Total size of folder %s is: %d\n", folder_name, size);

    getch();


    return 0;
}



