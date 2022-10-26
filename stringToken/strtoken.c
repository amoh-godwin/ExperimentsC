#define __STDC_WANT_LIB_EXT1__ 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    char* ss = malloc(1000);
    char* ass = malloc(1000);
    //ass = "some one";

    char input[] = "Abirdcamedown";// the walk";
    char two[1000];
    char* pp = "this is love";
    memcpy_s(two, 1000, pp, strlen(pp));

    printf("All is well %s \n", two);
    printf("Parsing the input string '%s' \n", input);

    printf("space many %d: \n", strcmp(input, "A bird came down the walk"));

    char* token = strtok(input, " ");
    printf("token here: %s \n", token);
    snprintf(ss, 1, "%s", "");
    int n = 0;
    while(token) {
        printf("token %d : %s \n", ++n, token);
        if(strcmp(ss, "") == 0) {
            snprintf(ss, 1000, "%s", token);
            token = NULL;
        }
        else {
            snprintf(ss, 1000, "%s%%20%s", ss, token);
            //puts(token);
            token = strtok(NULL, " ");
        }
    }


    //char **d = &input;

    printf("ass here:  %s\n", ss);


    printf("The contents now: '");
    for(size_t n = 0; n < sizeof input; ++n) {
        input[n] ? snprintf(ss, 1000, "%s%s", ss, "j") : snprintf(ss, 1000, "%s%s", ss, "l");
    }
    puts("'");
    printf("token222 here: %s \n", ss);

    free(ss);
    free(ass);
    free(input);

    #ifndef __STDC_LIB_EXT1__

    #endif

}

 // __STDC_LIB_EXT1__
