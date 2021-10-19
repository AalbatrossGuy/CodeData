#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// prototype defined
int test(void);
int structest(void);
int small(void);
int Arr_Length(void);
int strucpoint(void);
int anotherfunc(void);


int main(void){ 
    //printf("Hello World");
    return 0;
}

int test(void){
    char *mstring = NULL;
    mstring = (char *) calloc(11, sizeof(char)); 
    fgets(mstring, 10, stdin);
    printf("%s\n", mstring);
    free(mstring);
}

struct date {
    int month;
    int date;
    int year;
};

struct date Today = {10, 20, 2021}; // initilizes the variables of the structure...similar to array...positional way.

int structest(void){
    struct date today;
    today.month = 10;
    printf("%d\n", today.month);
    today.year = 2021;
    printf("%d\n", today.year);
}

int small(void){
    struct date mydate;
    mydate.month = 12;
    printf("Small: Mydate: %d\n", mydate.month);
}

// Function to find out the length of an array in c
int Arr_Length(void){
    char arr[] = {"This is a lubby dubby string Hi There I am Kishaloy Roy"};
    int arrlen = (sizeof(arr)/sizeof(arr[0])) - 1;
    printf("The length of the array is: %d\n", arrlen);
}

int strucpoint(void){
    struct date *pDate = NULL;
    pDate = &Today;
    printf("%d\n", pDate->month); // calling (*pDate).month in a simpler way.
}

int anotherfunc(void){
    char name1[20] = {"This is compare"};
    char name2[20] = {"This is compare#3"};
    int res = strcmp(name1, name2);
    printf("%d\n", res);

}

