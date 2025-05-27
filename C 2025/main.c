//
// Created by AG on 5/22/2025.
//

#include <ctype.h>
#include <stdbool.h> // _Bool is a core type while bool is a macro provided by stdbool.h for more intuitive choice holding.
#include <stdio.h> // tells the preprocessor to look for a file in one or more standard directories.
#include <stdlib.h> // if #include "header.h" is used, it means, it's an user defined header file and tells the preprocessor to look for it in the current directory.
#include <string.h> // string functions.

int test_func();

int main() {
    // enum daysOfWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    // enum daysOfWeek today = Saturday;
    // printf("%d", today);
    // printf("Enter number: ");
    // int test = 0;
    // scanf("%d", &test);
    // printf("test = %i", test);
    // ternary operation syntax: If Condition is true ? then value x: else value y
    // short int yz;
    // int yz_size = sizeof(yz);
    // printf("SIZE = %d", yz_size);
    // printf("\n");
    // for (int i = 0; i<10; i++) {
    //     printf("%i", i);
    // }
    // printf("\n");
    // for (int i = 0; i<10; ++i) {
    //     printf("%i\n", i);
    // }
    // int arr[2][2] = {1, 1, 1, 1};
    // for (int i = 0; i<2; i++) {
    //     for (int j = 0; j<2; j++) {
    //         printf("\n");
    //         printf("i = %d, j = %d\n", i, j);
    //         printf("%d", arr[i][j]);
    //     }
    // }
    // using prototypes is best practice.
    // parameters for a function are the "placeholders" for the arguments given. int func(int a, int b) has the parameters a and b where you give the arguments, say, pre-defined variables x and y.
    // best practice tells you to not have more than 5 parameters in a function.
    // char ch[10];
    // printf("Hello World\n");
    // in multiple boolean operations in a single statement, if the first boolean value is false, the second operation doesn't executes. x = a && b && y++, if a && b is 0 (false), (b && y)/y++ never gets executed.
    // int number = 5;
    // printf("Number before editing: %d\n", number);
    // printf("Enter a number: ");
    // scanf("%d", &number);
    // printf("Number after editing: %d\n", number);
    // printf("Enter a string and a number: ");
    // scanf("%s %d", ch, &number); // when taking input for a string in a character array, and (&) is not required.
    // printf("The string is %s and the integer is %d\n", ch, number);
    // double x; // for a float/double value, 174e4 means 174 x 10^4
    // scanf("%lf", &x); // for reading in double use lf, probably stands for long float :|
    // printf("%lf", x);
    // char exampleString[10] = "MY STRING";
    // int test = sizeof(exampleString);
    // printf("TEST = %s", exampleString);
    test_func();
    return 0;
}
// linking basically means connecting the source .obj file with other external libraries to finally create a .exe file that can be run.
// 1 byte = 8 bits
// type casting is advised when explicitly converting data types, e.g., int x = (int) <float-variable>
/* %s -> strings
 * %d -> integers
 * %i -> while outputting, same as %d. For inputs, %i lets you enter hexadecimal numbers
 * %c -> characters
 * %f -> floats
 * %lf -> prints long format of double
 * %g -> prints shorter value of double
 * %e -> prints the scientific notation of double
 */
// in loop statements, use ++<var> so it executes at the end of every loop cycle and not before.
/*
 * switch case format:
 * switch (expression) {
 *  case value1:
 *      statement;
 *      break;
 *  case value2:
 *      statement;
 *      break;
 *  case valuen:
 *      statement;
 *      break;
 *  default:
 *      statement;
 *      break;
 *  }
 */

// to initialize certain elements from an array, do this: float sample_data[500] = {[2] = 300.0, [4] = 800.0, [1] = 100.0};
// to find size of an array, use: int n = sizeof(arr) / sizeof(arr[0]);
// in order to declare a string, use char array, e.g., char exampleString[desired length of string + 1] since a string always has a null terminator, a.k.a, \0 at the end.
// Hence, every string, when creating, should have desired_size + 1 space declared.
// Best practice tells you to NOT declare the size for the string. Let the compiler decide the size of the string for you, e.g., char myString[] = "Hello World";
// When taking string input, & is not required before the variable name, similar to char input.
// Two strings cannot be compared with ==. == operator cannot compare complex data types like structs and arrays.
// Two strings can be compared by using strcmp function.
// size_t data type is used to declare variables meant to hold the size of a token.

int test_func() {
    char mystr[] = "ABCDEFGHIJ";
    char nonvaluearr[47];
    size_t len = strlen(mystr);
    printf("The length of the string is: %llu\n", len);
    strcpy(nonvaluearr, "It gets assigned here!"); // since strings cannot be assigned via assignment operator, strcpy() is equivalent to assignment operator (=) for strings.
    strncpy(nonvaluearr, "It gets assigned here!", 10); // strncpy() is equivalent to assignment operator (=) for strings. However, it takes a third argument to count how many letters to copy. It's a safer and preferred way to copy strings to avoid errors.
    strncpy(nonvaluearr, "It gets assigned here!", sizeof(nonvaluearr) - 1); // Fail-safe method to prevent buffer overflows.
    strcat(nonvaluearr, "It gets appended here!"); // strcat() is equivalent to concatenation operator (+) for strings. The string gets APPENDED after the first string.
    strncat(nonvaluearr, mystr, sizeof(mystr) - 1); // Fail-safe to mention how much to copy.
    int compare = strcmp(mystr, nonvaluearr); // If value < 0, str1 is less than str2. If value > 0, str1 is greater than str2. If the value is 0, both strings are equal.
    int compare2 = strncmp(mystr, nonvaluearr, 10); // Fail-safe method to prevent buffer overflows. MaxCount is the count till which the comparison/search will happen.
    // Use strncmp to search for a segment of word from a sentence, e.g., to search for astro in astronomy; do strncmp(sentence, word-to-search, 5)
    printf("The result of the comparison is: %i\n", compare);
    printf("%s", nonvaluearr);
    printf("\n");
    // To find a single character in a string, use strchr(string-to-be-searched, character-that-you-are-looking-for). To find a sub-string, use strstr(string-to-be-searched, desired-substring)
    // To break a string into words, a.k.a, tokenizing it, break it with a delimiter using strtok(string-to-be-tokenized, string-of-delimiter-characters)
    // Analyzing strings: islower(), isupper(), isalpha(), isdigit(), etc.
    char *pGetChar = strchr(mystr, 'G');
    printf("The address of G is %p and the string after the first hit is %c\n", &pGetChar, pGetChar);
    char *pGetChar2 = strstr(mystr, "HIJ");
    printf("The address of HIJ is %p and the string after the first hit is %s\n", &pGetChar2, pGetChar2);
    char str[] = "THIS-IS-A-TEST-STRING";
    char *pGetChar3 = strtok(str, "-"); // It actually starts tokenizing from the first, hence, the first break would be THIS and not IS.
    printf("The address of the token is %p and the string after the first hit is %s\n", &pGetChar3, pGetChar3);
    pGetChar3 = strtok(NULL, "-"); // After getting the first token, NULL should be given as first argument to let strtok() know to continue tokenizing the required string.
    printf("The address of the second token is %p and the string after the second hit is %s\n", &pGetChar3, pGetChar3);
    bool is_true = isupper(mystr[0]);
    printf("The result of isupper() is: %i\n", is_true);
    // Converting a string to upper/lower case requires per character conversion
    for (int i = 0; (nonvaluearr[i] = (char) toupper(nonvaluearr[i])) != '\0'; ++i) {} // IMPORTANT ONE LINER OPERATION?
    
}