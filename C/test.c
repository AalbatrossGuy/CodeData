#include<stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main(void){
    short int xo = 200; // Test for short int 
    int x = sizeof(int);
    // printf("%d\n", x);
    
    enum primaryColor { red, green, blue };
    enum primaryColor myColor = green;
    enum primaryColor colorRed = red;
    
    // printf("%d\n", myColor);
    // printf("%d\n", colorRed);
    
    unsigned int abcd = 2000; // unsigned can only store positive values.
    // printf("%u\n", abcd);
    
    int arr[5];
    size_t arr_length = sizeof(arr) / sizeof(int);
    
    for (int i = 0; i<arr_length+1 ; i++){
        arr[i] = i;
    }
    
    for (int i = 0; i<arr_length+1; i++){
        printf("%i, ", i);
    }
    return 0;
}