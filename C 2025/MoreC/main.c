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


// A heap is opposite of stack. It's a hierarchical data structure. It's a large pool of memory that can be used dynamically. The memory in heap is not automatically managed.
// The heap is programmer managed. The memory needs to be explicitly allocated (malloc, calloc) and deallocated (free). Failure to do so will result in memory leaks.
// There is no virtual limit to heap size. Its only limit is the physical size limit of memory in the machine. Variables created in the heap are accessible anywhere in the program. Heap is slightly slower for i/o operations.
/* Use The Heap When:
 * large block of memory needs to be allocated:
 *      a large array
 *      a big struct
 *      big data types, etc.
 * global variables are required
 * arrays or structs need
*/
int main() {
    printf("%d\n", test_func());
}
