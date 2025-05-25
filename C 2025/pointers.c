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
    int testNum = 10;
    int * pTestNum = &testNum;
    *pTestNum += 20; // If you call the value, the pointer is pointing to, normal arithmetic calculations can be done. When using *pTestNum += 20, it's getting the value of the address of testNum and then adding 20 to it. Since testNum also points to that same address, the value of testNum changes too!
    ++*pTestNum; // ++pTestNum is the same as pTestNum += 1. Increments the value by 1
    printf("The value of ptestNum is: %i and the value of testNum is: %i\n", *pTestNum, testNum);
    int aNum = 0;
    int * pANum = &aNum;
    printf("Enter a number: ");
    scanf("%d", pANum); // scanf() takes a pointer as its second argument. Since variables are not pointers, we used & to store the inputted value in the address of that variable. However, since pointer already points to an address, no need to use &. Simply using the pointer variable works.
    printf("The value of aNum is: %i\n", aNum);
    // Always check for NULL before using a pointer!!!
    // To point to a constant value for a pointer variable, use this: const <data-type> *<variable> = &<variable>;
    int constpointer = 69;
    const int * pConstPointer = &constpointer; // this means that the value of the address of constpointer, i.e., 69, is constant and cannot be changed. The pointer itself is not constant. The address of a variable that it's storing CAN be changed.
    printf("pConstPointer is pointing to: %i\n", *pConstPointer);
    // Hence, doing something like
    // *pConstPointer = 79; // will give an error
    // In order to change the value, change it directly from the variable and not the pointer.
    constpointer = 79; // works!
    pConstPointer = &testNum; // works because the pointer itself is not constant.
    // NOTE: Since the pointer was declared with a const keyword, the value of the address that it points to CANNOT be changed. However, the address of a variable that it points to CAN be changed!!!!!!

    // In order to make the address of the variable that the pointer is pointing to unchangeable but value changeable, use this syntax: <data-type> * const <pointer-variable> = &<variable>;
    int * const trulyConstantPointer = &constpointer; // The pointer itself cannot be changed now. The address stored in it cannot be changed, but the value it points to can be changed!
    printf("trulyConstantPointer is pointing to: %i\n", *trulyConstantPointer);
    *trulyConstantPointer = 89; // works!
    printf("The value of trulyConstantPointer after changing it's value is: %i\n", *trulyConstantPointer);
    // In const int *pVariable, the value gets fixed. The address can be changed. Even if the address is changed, the value of that new address still cannot be changed. It has to be changed directly from the variable itself.
    // In int * const pVariable, the address gets fixed. The value can be changed.

    // To make both the value and address constant, use this syntax: const <data-type> * const <pointer-variable> = &<variable>;
    int fullConst = 100;
    const int * const fullConstPointer = &fullConst;
    printf("fullConstPointer is pointing to: %i\n", *fullConstPointer);
    return 0;
}

/* const <data-type> * ... =====> Value cannot be changed, address can be changed.
 * <data-type> * const ... =====> Address cannot be changed, value can be changed.
 * const <data-type> * const ... =====> Neither address nor value can be changed.
*/