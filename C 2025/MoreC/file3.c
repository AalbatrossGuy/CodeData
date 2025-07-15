#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void variadic();
double average(double v1, double v2, ...);
void recursionahh();
int factorial(int n);

int main() {
    variadic();
    double avgResult = average(10.1, 20.3, 35.66, 40.65, 99.31);
    printf("The result of average() is: %f\n", avgResult);
    recursionahh();
    int fac = factorial(5);
    printf("The factorial is: %i\n", fac);
    return 0;
}

void variadic() {
    // The word variadic means some kind of change/variation is involved.
    // A variadic function is typically used when the total number of arguments for a function is unknown.
    // A single function could have 'n' number of arguments.
    // printf() is a variadic function. It's no. of arguments depends on the no. of format specifies used when outputting to the screen.
    // In order to make custom variadic functions, <stdarg.h> provides routines to write variadic functions.
    /* A variadic function has two parts :-
     * - Mandatory arguments
     *      - At least one is required and is the first one in the sequence.
     *      order is important
     * - Optional arguments
     *      - Listed AFTER mandatory arguments.
     */
    // va_list is used in situations in which access to optional parameters, and it's argument list is needed.
    // It represents a data object used to hold the parameters corresponding to the ellipsis part of the parameter list.
    // va_start connects argument list with some argument pointer.
    // va_arg fetches the current argument connected to the argument list.
    // The data type of the argument is needed to know.
    // va_end is used for cleanup, when the variable argument list is no longer needed.
    // va_copy is used in situations when current location is needed to be saved.

    // STEP 1: Create a function with a variable no. of args.
    // STEP 2: Provide a function prototype using ellipsis (... are called ellipsis). Must've at least one fixed argument before it.
    // example: void test_function(int n, ...); void test_function_2(int n, const char * s, ...);
    // STEP 3: Create a va_list type variable in the function definition. Initialise it to an argument list. Copy argument list to the va_list using va_start.
    /* Example:
     * double average(double v1, double v2, ...) {
     * va_list pArg; // pointer for variable argument list.
     * <code>
     * va_start(pArg, v2);
     * <code>
     * }
     */
   // va_start() takes two argument. The va_list as first argument and the last fixed argument as the second argument.
   // STEP 4: Access the contents of the argument list using va_arg(). va_arg() takes two arguments, va_list as 1st arg and a type name as 2nd arg.
   // The first time va_arg() is called, it returns the first argument in the list, 2nd time returns the 2nd argument, 'n' times returns the nth argument.
   // Example:
   /* double exampleFunc(int lim, ...){
    *   va_list pAarg;
    *   va_start(pAarg, lim);
    *   double variable = va_arg(pAarg, double);
    *   va_end(pAarg);
    *   }
    */
   // STEP 5: Clean up using va_end(). Takes va_list() as an argument and resets the pointer, in this case, pAarg, to NULL.
   // A last argument in the variable argument list could have a fixed value known as the sentinel value that can be detected because it's value is known/expected.
   // Another approach is to use the first argument to specify the count of no. of arguments in total or in the variable part of the argument list.


   // va_arg() provides no way to back up previous arguments. va_copy() helps in preserving the list by copying the list.
   // va_copy() takes two arguments, both of type va_list. It copies the second argument to the first argument.
   // va_copy() will only copy the values from where the pointer is. It won't copy anything before the pointer.
}


double average(const double v1, const double v2, ...) {
    va_list pArg;
    double sum = v1 + v2;
    va_start(pArg, v2); // Put arguments in the argument list
    double result = 0;
    int count = 2; // at least 2 fixed variables
    while ((result = va_arg(pArg, double)) != 0.0) { // Checking to see if the args are non-zero. The function assumes that the last argument is zero hence sets it as the loop break condition.
        sum += result; // adding the arguments with sum that already has the value of the two fixed arguments.
        ++count;
    }
    va_end(pArg);
    return sum / count;
}

void recursionahh() {
    // basically, recursion is a function that calls itself, and it's fucking annoying other than the fact that it's memory AND CPU hungry.
    // Highly susceptible to infinite looping.
    // A function that calls itself (recursion) MUST contain a conditional test/base case that terminates the recursion.
    // When the function is called with a more complex use case, it divides the problem into two conceptual pieces :-
    /*  - A piece that the function knows what to do
     *  - A smaller version of the original problem
     */
    // For recursion to terminate, the sequence of smaller and smaller problems must converge on the base case.
    // When the function recognizes the base case, the result is returned to the previous function call. A sequence of returns goes allllll the way up to the original call of the function thus returning the final result.
    // Visualization (considering function 4 hits the condition):-
    /* function 1 -> function 2 -> function 3 -> function 4
     * function 4 then returns the control back to function 3, function 3 returns the control back to function 2, function 2 returns the control back to function 1, i.e, the original function.
     * function 1, 2, 3, 4 are all the same recursion function.
     */
    // Tail recursion is when the recursive call in the function comes at the END of the control flow.
}

int factorial(int n) {
    // The most common recursion example.
    // The factorial of any positive integer 'n' > 0 is n * factorial(n-1)
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}