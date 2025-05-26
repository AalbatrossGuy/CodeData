//
// Created by AG on 5/26/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
    // dynamically allocated memory reserves space in a memory area called the heap. The heap stays till the entirety of the program.
    // all other functions, variables, etc. are stored in stack. The stack is short-lived compared to the heap, and its lifetime is only till execution.
    // hence, heap is used to dynamically allocate and store the memory till the program's lifetime.
    // The heap is completely user-controlled, and space must be freed after the work is done.
    // In order to allocate memory at runtime, the simplest function is: malloc() which takes number of bytes of memory that we want allocated. It returns the address of the first byte of memory that it allocated for us.
    int *pTest = (int *) malloc(100); // allocate 100 bytes in memory for pTest
    // NOTE: The above is bad code. Use sizeof() operator to allocate memory. For example, if you want to allocate memory for 10 integers, use 10 * sizeof(int)
    int *pTrueTest = (int *) malloc(10 * sizeof(int)); // Allocate memory for 10 integers.
    // NOTE: It is always a good idea to check if the memory was allocated without failure or not. To deal with failure do this:
    if (pTrueTest == NULL) {
        // Do something to deal with memory allocation failure;
        exit(1);
    }
    *pTrueTest = 25;
    printf("The address of the first byte of memory (pTest) allocated is: 0x%p\n", pTest);
    printf("The address of the first byte of memory (pTrueTest) allocated is: 0x%p and it's value is %i\n", pTrueTest, *pTrueTest);
    // MEMORY MUST BE CLEARED AFTER DESIRED WORK IS DONE FOR OTHER PROGRAMS TO ACCESS IT.
    free(pTrueTest);
    free(pTest);
    // Always set the pointer to NULL after the memory that it pointed too was freed.
    pTrueTest = NULL;
    pTest = NULL;

    // A dangling pointer refers to a pointer that lost access to a memory location that it had before, usually due to deallocation of that memory or a memory which is no longer valid.
    // Use calloc to allocate memory as a number of elements of a given size. Besides allocating, calloc also initializes the memory; hence all bytes are zero that is more advantageous than malloc().
    // calloc syntax: calloc(number-of-data-items, size-of-each-data-item);
    int * pCall = (int *) calloc(10, sizeof(int)); // allocate and initialize memory for 10 elements of type int.
    *pCall = 10;
    printf("The address of the first byte of memory (pCall) allocated is: 0x%p and it's value is %i\n", pCall, *pCall);
    free(pCall);
    pCall = NULL;
    // realloc is used to reallocate previously allocated memory to reduce or extend it's size that was set by malloc() or calloc().
    // realloc syntax: realloc(pointer-containing-an-address-that-was-set-by-malloc-or-calloc, size-in-bytes-of-the-new-memory-that-is-to-be-allocated)
    // When realloc allocates new memory, it copies the contents of the previous memory into the new memory which is it's unique feature.
    // FAULTY AHH CODE FUCKING HELL WHAT THE FUCK IS WRONG WITH THIS BULLSHIT
    // char *str = NULL;
    // str = malloc(6);
    // if (str == NULL) {
    //     free(str);
    //     exit(1);
    // }
    // strcpy(str, "HELLO");
    // printf("The address of str is: %p and it's value is: %s\n", str, str);
    // str = (char *) realloc(str, 12);
    // if (str == NULL) {
    //     free(str);
    //     printf("Insufficient memory to allocate memory for str.");
    //     exit(1);
    // }
    // strcat(str, " WORLD");
    // printf("The address of reallocated str is: %p and it's value is: %s\n", str, str);
    // free(str);
    // str = NULL;
    return 0;
}
