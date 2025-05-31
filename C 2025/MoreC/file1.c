//
// Created by AG on 5/31/2025.
//

#include <stdio.h>
#include <stdlib.h>

struct myStruct {
    int arraySize;
    int arr[];
};

void func1();
void func2();

int main() {
    func1();
    func2();
    return 0;
}

void func1() {
    // A Variable Length Array (VLA) is an array whose length or size is defined in terms of an expression evaluated at execution time. This is done using dynamic memory allocation
    // when the array's length is not known during compilation time. The term "variable" in VLA does not mean that the length of the array can be modified AFTER it has been created.
    // It means that a variable can be used to specify its dimensions when FIRST creating that array.
    // Flexible array members example:
    int size = 10;
    struct myStruct *ptr;
    // When making flexible array members, memory is generally dynamically allocated.
    ptr = malloc(sizeof(struct myStruct) + size * sizeof(int)); // When allocating space for flexible array members, if arr[] is empty, the sizeof returns the size for the struct members EXCEPT the empty array.
    // Hence, the size of the array needs to be added with the size of the structure, which is actually, sizeof(struct myStruct) minus the size of the array.
    ptr->arraySize = size;
    ptr->arr[0] = 10;
    printf("The 0th element of the array is: %i and it's address is 0x%p\n", ptr->arr[0], &ptr->arr[0]);
    // A flexible array member can only be defined using a struct, and it must be the last element of the struct. Each struct can contain AT MOST one flexible array. A struct cannot have ONLY flexible array. It must have fixed members too.
    // A struct containing a flexible array as its member cannot be a member of another struct (can't be nested).
    // A struct with a flexible array member cannot be statically initialized. It must be dynamically allocated.

    free(ptr);
}

void func2() {
    typedef const int alpha;
    alpha beta = 69; // the same as const const int beta = 69,
    // the volatile type qualifier tells the compiler explicitly that the specified variable will change its value. It prevents the compiler from caching variables.
    // A variable should be declared volatile when its value changes unexpectedly. The variable must be reloaded every time it is used instead of caching it in the cpu register.
    /* Only 3 types of variables should use volatile:
     * memory-mapped peripheral registers
     * global variables (non-stack variables) modified by an interrupt service routine.
     * global variables accessed by multiple tasks within a multi-threaded application.
     */
    // A value can be both const and volatile.
    // syntax:
    volatile alpha yeta = 70;
    volatile int gamma = 69;

}