#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>

//int AverageMarks(int suba, int subb, int subc);

int main(void){
//    int result = AverageMarks(20, 30, 40);
//    printf("%d", result);
    int values[5] = {1, 10, 50, 30, 20};
    int *pValues = NULL;
    char teststring[] = "This is a test line.";
    char *pTestString = NULL;
    pTestString = teststring;
//    printf("The address of the first char is %p and the value is %c\n", pTestString, *pTestString);
    ++pTestString;
//    printf("The address of the second char is %p and the value is %c\n", pTestString, *pTestString);
    pValues = values;
    //pValues+=2; Increment the pointer by n value or simply increment or decrement it by one using ++ or --;
    printf("This is a test line %d\n", *pValues);
}


//int AverageMarks(int suba, int subb, int subc){
//    int average = (suba+subb+subc)/3;
//   return average;
//}
