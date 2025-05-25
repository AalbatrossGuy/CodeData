//
// Created by AG on 5/25/2025.
//

#include <stdio.h>
#include <stddef.h>
#include <string.h>

// pointers gonna be the end of me 🥀
int main() {
    // Pointers occupy 8 bytes of memory space.
    // int number = 99 has an address of 1008.
    // Always initialize a pointer. NEVER declare it uninitialized.
    // In order to declare a pointer that doesn't point to anything, do this:
    int *pExamplePointer = NULL;
    // int *pnumber = &number, assigns the address of number, i.e., 1008 to pnumber variable. The asterisk (*) makes it a pointer, which basically means that pnumber is pointing to the address of number
    // When the pointer points to an address, it also points to the value of that address. In this case, the value of address 1008 is 99.
    // Syntax for defining a pointer -> <data type> *<variable name>. Best practice tells you to start a pointer with "p" followed by the name of the variable for which you're making the pointer.
    // Best practice tells you to give a space between asterisk (*) and the pointer name when declaring it and removing the space when dereferencing it.
    int myNum = 100;
    int * pMyNum = &myNum; // This declares the pointer pMyNum and assigns it the address of myNum. The value of the address of myNum is 100.PRETTY FUCKING SIMPLE RIGHT
    int result = *pMyNum + 10; // The value of a pointer can be dereferenced and added/subtracted in this manner.
    // to show the value of the address the pointer, pMyNum is pointing to, use *pMyNum when printing. This points to the value of the address, i.e., 100
    printf("The value of pMyNum is: %i and the address of the pointer is: 0x%p\n", *pMyNum, &pMyNum); // Calling the pointer to show the value of the address is called dereferencing a pointer.
    printf("The value of myNum is: %i and the address of myNum is: 0x%p\n", myNum, &myNum); // Both myNum and pMyNum have the same value cause ultimately, pMyNum is pointing to the address, the value of myNum. However, myNum has a separate address that can be accessed by using &myNum.
    printf("The result of the addition is: %i\n", result);
    char ch = 'F'; // same for character pointers (another example)
    char * pCh = &ch;
    printf("The value of ch is: %c and the address of the pointer is: 0x%p\n", *pCh, &pCh);
    int * p, q; // p is a pointer (uninitialized) and q is an int data type.
    // To get the size of a pointer, use the sizeof() function same as other variables.

    return 0;
}