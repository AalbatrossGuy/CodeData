#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Union();

union car {
    int value;
    float price;
};

int main() {
    Union();
    return 0;
}

void Union() {
    // A union is a derived type with members that share the same storage space.
    // It is used when it's necessary to store different types of data in the same storage area.
    // Each element in a union is called member.
    // A union can have many members. Only one member can contain a value at any given time, so only one access of a member at a given time.
    // The members of a union can be of any data type. In most cases, unions contain two or more data types.
    // Referencing data in an union with a variable of the wrong type is a logic error.
    /* The operations that can be performed on a union are:
     * - assigning a union to another union of the same type.
     * - taking the address of a union variable.
     * - accessing union members.
     */
    // In a struct, whenever an instance is created, the compiler creates & allocates space for all its members separately.
    // In a union, all the members have an offset of zero. A union is created with enough space for its largest field (its data type).
    // If there are 5 variables in a union, all of them will go in the same space in memory.
    // Use a structure when the construct should be a group of other things.
    // Use a union when the construct can be one of many different things but only one at a time.
    // Unions are typically used where space is premium but more importantly for exclusively alternate data. Unions ensure that mutually exclusive states remain mutually exclusive.
    // A struct can hold an int and a double and a char. A union can hold an int or a double or a char.
    // The process of defining a union is:
    /* union [tag] {
     * data_type_1 identifier_1;
     * data_type_2 identifier_2;
     * data_type_n identifier_n;
     * } optional_variable_definition;
     */
    // When a union is defined, no memory is allocated. To allocate memory for the union type, variables need to be created.
    union car car1, car2;
   // A struct can have a union. That gives access to more variables. However, the catch is that, only one variable of the union member can be accessed at a time.
   // Accessing of union members is the same way as struct. Use dots to access members. use -> for pointer variables' access.
    car1.value = 69;
    union car *car3 = &car1;
    car3->price = 1.5;
    
}