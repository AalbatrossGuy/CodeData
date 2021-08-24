#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int test(void);

int main(void){
    /*printf("Hello, World");*/
    /*printf("\n");*/
    test();
    return 0;
}

int test(void){
    char *mstring = NULL;
    mstring = (char *) calloc(11, sizeof(char)); 
    fgets(mstring, 10, stdin);
    printf("%s\n", mstring);
    free(mstring);
}
