//
// Created by AG on 5/26/2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct date {
    // members of the struct, date.
    int month;
    int day;
    int year;
};

// Declare and assign a variable to the struct at the same time.
struct food {
    int calorie;
    int sodium;
    int potassium;
} Chips;

// struct for one time usage.
struct {
    int magnesium;
    int salt;
    int sugar;
} Soda;

// Nested Structures
struct time {
    int hour;
    int minute;
    int second;
};
struct dateAndTime {
    struct date sdate;
    struct time stime;
};

struct intPtr {
    int * p1;
    int * p2;
};

struct charPtr {
    char * firstName;
    char * lastName;
};

struct characters {
    char firstName[12];
    char lastName[10];
    int letters;
};

void exampleCharPtrStruct(struct charPtr * ptr);

int main() {
    // Structs are used to group elements/multiple data attributes together.
    struct date today;
    today.month = 5;
    today.day = 26;
    today.year = 2025;
    // Structs can also be initialized like this:
    struct date today2 = {5, 26, 2025};
    struct date today3 = {10, 13}; // Can be semi-initialized
    struct food Chips = {19, 20, 33};
    printf("Today's date is: %i/%i/%i\n", today.month, today.day, today.year);
    printf("%i\n", Chips.calorie);
    // An array of structures can also be declared like how normal arrays are declared:
    struct date Dates[4]; // Each Date element is a struct itself.
    Dates[2].month = 10;
    Dates[2].year = 2013;
    // Initializing an array of structures is the same as initializing as a multidimensional array.
    struct date myDates[3] = {{1, 1, 2025}, [0] = {3, 3, 2025}};
    printf("The date of the third element of the array is: %i/%i/%i\n", myDates[0].month, myDates[0].day, myDates[0].year);
    printf("The date of the third element of the array is: %i/%i/%i\n", Dates[2].month, Dates[2].day, Dates[2].year);


    // For accessing and using nested structs
    struct dateAndTime todayAndTime;
    todayAndTime.sdate.month = 5;
    todayAndTime.sdate.day = 26;
    todayAndTime.sdate.year = 2025;
    todayAndTime.stime.hour = 12;
    todayAndTime.stime.minute = 30;
    todayAndTime.stime.second = 45;
    printf("Today's date is: %i/%i/%i\n", todayAndTime.sdate.month, todayAndTime.sdate.day, todayAndTime.sdate.year);
    printf("Today's time is: %i:%i:%i\n", todayAndTime.stime.hour, todayAndTime.stime.minute, todayAndTime.stime.second);


    // Structures & Pointers
    // For big structures, passing them as arguments is time and resource hungry. Passing a pointer is more efficient.
    // This is because a pointer struct copies only the addresses, which is more efficient than copying all the data attributes in a struct.

    struct date *pDate = &today;
    pDate->month = 3;
    printf("The date is: %i/%i/%i\n", today.day, pDate->month, today.year);

    struct dateAndTime myDate;
    // The structure pointer must point to a struct variable. Think of it like using a bike (pointer) to bring fuel to an empty car (variable, in this case, myDate).
    struct dateAndTime *pMyDate = &myDate;
    pMyDate->sdate.month = 10;
    pMyDate->sdate.day = 13;
    pMyDate->sdate.year = 2013;
    pMyDate->stime.hour = 12;
    pMyDate->stime.minute = 30;
    pMyDate->stime.second = 45;
    printf("The date is: %i/%i/%i and the time is: %i/%i/%i\n", pMyDate->sdate.day, pMyDate->sdate.month, pMyDate->sdate.year, pMyDate->stime.hour, pMyDate->stime.minute, pMyDate->stime.second);

    struct intPtr myIntPtr; // A structure containing pointers can be declared like non-pointer variables. myIntPtr itself is not a pointer but a structure variable containing pointers.
    int i1 = 110, i2 = 220;
    myIntPtr.p1 = &today.month;
    myIntPtr.p1 = &i1; // this is valid too
    myIntPtr.p2 = &i2; // this is valid too
    myIntPtr.p2 = &today.day;
    printf("The month is: %i and the day is: %i and their address is 0x%p and 0x%p respectively.\n", *myIntPtr.p1, *myIntPtr.p2, &myIntPtr.p1, &myIntPtr.p2);

    // Simple character structures should be used if no strings are previously created and/or allocated.
    struct characters myName = {"Aalbatross", "Guy"};
    printf("The first name is: %s and the last name is: %s\n", myName.firstName, myName.lastName);

    // Character Pointer Structures
    // Character Pointer Structures should only be used when the strings are already created and allocated elsewhere in the program.
    char *myFirstName = "Aalbatross";
    char *myLastName = "Guy";
    struct charPtr myCharPtr;
    myCharPtr.firstName = myFirstName;
    myCharPtr.lastName = myLastName;
    printf("The first name is %s and the last name is %s\n", myCharPtr.firstName, myCharPtr.lastName);
    struct charPtr *pCharPtr;
    exampleCharPtrStruct(pCharPtr);
    return 0;
}

// EXAMPLE OF USING STRUCT CHAR POINTERS WHEN WE NEED TO DYNAMICALLY ALLOCATE SIZE FOR CHAR ARRAYS
void exampleCharPtrStruct(struct charPtr * ptr) {
    char temp[20];
    printf("Enter the first name: ");
    fgets(temp, sizeof(temp), stdin);

    // allocate memory for storing the input string
    ptr->firstName = (char *) calloc(21, sizeof(char));
    ptr->lastName = (char *) malloc(strlen(temp) + 1);

    // save input
    strcpy(ptr->firstName, temp);
    printf("Enter the last name: ");
    fgets(temp, sizeof(temp), stdin);
    strcpy(ptr->lastName, temp);
    printf("The first name is %s and the last name is %s\n", ptr->firstName, ptr->lastName);
    free(ptr->firstName);
    free(ptr->lastName);
    ptr->firstName = NULL;
    ptr->lastName = NULL;
}