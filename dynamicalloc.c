#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

int pointers(void); // prototype declaration
int practice(void);
int test(void);
int char_pointer(void);


int main(void){
    //pointers();
    //practice();
    //test();
    char_pointer();
}


int pointers(void){
//  int result = AverageMarks(20, 30, 40);
//  printf("%d", result);
    int values[5] = {1, 10, 50, 30, 20};
    int *pValues = NULL;
    char teststring[] = "This is a test line.";
    char *pTestString = NULL;
    pTestString = teststring;
    printf("The address of the first char is %p and the value is %c\n", pTestString, *pTestString);
    ++pTestString;
    printf("The address of the second char is %p and the value is %c\n", pTestString, *pTestString);
    pValues = values;
    //pValues+=2; Increment the pointer by n value or simply increment or decrement it by one using ++ or --;
    printf("This is a test line %d\n", *pValues);

}

int practice(void){
    //int *pMalloc = (int *) malloc(10*sizeof(int));
    int *pMalloc = (int *) calloc(10, sizeof(int)); // calloc is used over malloc because it not only allocates data on heap but also initializes them.
    printf("pMalloc = %p\n", pMalloc);
    pMalloc = (int *) realloc(pMalloc, 5); // reallocate memory...takes the number of bytes to reallocate the memory to.
    printf("pMalloc(reallocated) = %p\n", pMalloc);
    free(pMalloc);
}

int test(void){
    int *pList = NULL;
    pList = (int *) calloc(5, sizeof(int));
    if (pList == NULL){
        exit(1);
    }

    printf("pList address = %p and value = %d\n", pList, *pList);
    for (int i = 0;i<5;i++){ 
        pList[i] = i*i;
        printf("pList address is %p and it's value is %d\n", pList, pList[i]);
        printf("Added 1 to pList\n");

    }
    free(pList);
    
}

int char_pointer(void){
    char *pChar = NULL;
    pChar = (char *) calloc(10, sizeof(char));
    printf("Enter some text: ");
    fgets(pChar, 10, stdin); // params: pointer to write to, n bytes to read, input stream (in our case stdin).
    printf("The answer is: %s\n", pChar);
}
