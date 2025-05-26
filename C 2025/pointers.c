//
// Created by AG on 5/25/2025.
//

#include <stdio.h>
#include <stddef.h>
#include <string.h>

void array_pointer(); //prototype declaration. Some nigga said, also called forward declaration in C++
void pointer_arithmetic();

// pointers gonna be the end of me 🥀
int main() {
    // int number = 99 has an address of 1008.
    // Always initialize a pointer. NEVER declare it uninitialized.
    // In order to declare a pointer that doesn't point to anything, do this:
    int *pExamplePointer = NULL;
    // int *pnumber = &number, assigns the address of number, i.e., 1008 to pnumber variable. The asterisk (*) makes it a pointer, which basically means that pnumber is pointing to the address of number
    // The pointer is a variable that points to an address in memory.
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
    // scanf("%d", pANum); // scanf() takes a pointer as its second argument. Since variables are not pointers, we used & to store the inputted value in the address of that variable. However, since pointer already points to an address, no need to use &. Simply using the pointer variable works.
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
    // A pointer of type void * can contain the address of a variable of any data type.
    // void * is used as a parameter type or return value type with functions that deal with data in a type-independent way.
    void * pVoid = &fullConst;
    printf("The value of pVoid is: %i\n", *(int *)pVoid);
    char pc = 'B';
    pVoid = &pc;
    printf("The value of pVoid is: %c\n", *(char *)pVoid); // Syntax for dereferencing a pointer of type void is *(data-type *)pointer
    printf("=======================================================");
    array_pointer();
    pointer_arithmetic();
    return 0;
}

/* const <data-type> * ... =====> Value cannot be changed, address can be changed.
 * <data-type> * const ... =====> Address cannot be changed, value can be changed.
 * const <data-type> * const ... =====> Neither address nor value can be changed.
*/

/* When wanting to use a pointer as a parameter for a function in which you don't want to change the original value, use a const <data-type> * <pointer-name>.
 * This means that the value of the address that it's pointing to cannot be changed. However, the address it's pointing to can be changed.
 */

void array_pointer() {
    // The most common use case for pointers is in array operations.
    // The main reasons for using pointers to arrays are less memory and faster execution times. Pointers are more commonly used in character arrays.
    // When using pointer for arrays, it doesn't point to the array itself. It points to the type of element that is CONTAINED in that array.
    printf("\n");
    int arr[5] = {1, 2, 3, 4, 5};
    int * pArr = arr; // pArr points to the first element of the array. Since all arrays are pointers, you don't have to use & operator.
    printf("The value of pArr is: %i\n", *pArr); // The value of the address of pArr is the value of the first element of the array.
    pArr = &arr[2]; // When assigning the value of the non-first element of the array, usual syntax follows. Generally, other elements of the array is accessed by pointer arithmetic for pointer variables.
    printf("The value of pArr is: %i\n", *pArr); // The value of the address of pArr is the value of the third element of the array.
}

void pointer_arithmetic() {
    printf("=======================================================");
    printf("\n");


    // Pointer arithmetic is especially required when we want to sequence through the elements of an array.
    int arr[50] = {[3] = 39, [40] = 40, [41] = 59};
    int * pArr = arr; // Points to the first element. In order to get ith element, do * (pArr + i).
    * (pArr + 49) = 169;
    printf("The 2nd element is: %i\n", *(pArr + 2));
    printf("The 3rd element is: %i\n", *(pArr + 3));
    printf("The 49th element is: %i\n", arr[49]);
    pArr = &arr[40]; // This can be done too!
    printf("The 40th element is: %i\n", *pArr);
    ++pArr; // This can be done too!
    printf("The 41st element is: %i\n", *pArr);
    printf("The array is: %d\n", arr);
    // A neat way of looping through an array using pointers majorly. It generally is used in a function, but for example's sake it's used here:
    // int array[30]; const int n;
    // int sum = 0, * ptr;
    // int * const arrayEnd = array + n; // Address of the last element of the array.
    // for (ptr = array; ptr < arrayEnd; ++ptr) { // Looping till ptr hits the address of the last element in the array.
    //     sum += *ptr; // Just add the value to a sum variable to get the sum.
    // }
    // printf("The sum of the elements of the array is: %i\n", sum);
    // Since arrays and pointers are nearly the same, either of these is valid for function params: int array[] or int *array.
    float flt = 1.23456789;
    int* abcd = &flt;
    printf("The value of the address of flt is: %i\n", abcd);
    char string[] = "Hello";
    size_t length_string = strnlen(string, sizeof(string));
    size_t length_string2 = strlen(string);
    printf("The length of the string is: %llu\n", length_string2);
}