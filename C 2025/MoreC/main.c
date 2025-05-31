//
// Created by AG on 5/27/2025.
//

#include "headers/test.h"
#include <stdio.h>

// Static memory has a lifetime of the entire program duration.
// Stack memory has a lifetime of function runtime. As long as the function is working, the stack exists. When the function exits, the stack frees all memory it has.
// That memory then becomes available for other stack memory.
// If too much information is put in the stack, stackoverflow error occurs. It happens when all the memory in the stack is allocated and further allocations begin overflowing into other sections of memory.
// Stack memory is divided into successive frames. Each time a function is called, a fresh new stack frame is allocated to it.
// Example: local function variables.

// A heap is opposite of stack. It's a hierarchical data structure. It's a large pool of memory that can be used dynamically. The memory in heap is not automatically managed.
// The heap is programmer managed. The memory needs to be explicitly allocated (malloc, calloc) and deallocated (free). Failure to do so will result in memory leaks.
// There is no virtual limit to heap size. Its only limit is the physical size limit of memory in the machine. Variables created in the heap are accessible anywhere in the program. Heap is slightly slower for i/o operations.

/* Use The Heap When:
 * a large block of memory needs to be allocated:
 *  a large array
 *  a big struct
 *  big data types, etc.
 * global variables are required
 * arrays or structs need
*/

/* Four storage classes in C:
 * auto
 * register
 * extern
 * static
 * their syntax: <storage-class><data-type><variables>;
 */
// auto is used to declare variables of automatic storage duration. It's created when the block is entered, exists while the block is active and destroyed when the block is exited.
// local variables in C have automatic storage duration by default.
// automatic storage is a means for conserving memory.

// extern storage class tells that the variable is defined somewhere else, not within the same block it's been used.
// functions contained in separate files can communicate through extern variables.
// it makes the variable visible to ALL the program files.
// define the variable normally that is to be made global. When accessing that variable from another file, use the extern keyword which tells the compiler that the variable is present in another file and needs to be accessed from there.


// The register storage class is used to define local variables that should be stored in a register of a CPU instead of RAM. It makes working with that variable superfast since the variable is stored in the cpu instead of the memory.
// When declaring a variable as a register storage class, the compiler decides whether it actually gets stored in a register or not depending on hardware and implementation restrictions.
// register variables cannot be accessed using pointers since they don't have an address, considering they don't get stored in the memory.
// A memory location, i.e., a pointer itself can be stored in a register.
int main() {
    // example of storing a pointer in a register
    int var = 36;
    register int* pVar = &var;
    printf("%d\n", *pVar);
    printf("%d\n", test_func());
}
