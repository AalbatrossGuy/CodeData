#include <stdio.h>
#include <stdbool.h>

int main(){

    // format specifier examples.
    int intvalue = 10;
    float floatvalue = 300.00;
    double doublevalue = 8.44e+11; // 8.44 to the power of 11
    char charvalue = 'A';
    char str[] = {"Hi My name is babhalba"};
    bool boolvalue = false;
    printf("Integer val: %d\n", intvalue);
    printf("Float val: %f\n", floatvalue);
    printf("Double val: %e\n", doublevalue);
    printf("Double val #2: %g\n", doublevalue);
    printf("Char val: %c\n", charvalue);
    printf("String val: %s\n", str);
    printf("Boolean val (true is 1 false is 0): %i\n", boolvalue);
    printf("Float val using precision format specifier: %.3f\n", floatvalue);
    return 0;
}

