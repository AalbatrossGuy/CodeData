#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stddef.h>
//int main(){
//    int n;
//    int counter=0;
//
//    printf("A simple program To generate even numbers till the desired numbers\n\n");
//    printf("Enter number limit\n");
//    scanf("%d", &n);
//
//    while(counter<=n){
//        printf("Counter=%d\n", counter);
//        ++counter;
//        }
//    return 0;
//}
int Multiply(int x, int y);
int ReturnFunc(int x){
    int res = x+20.13;
    return res;
}
// Pointers occupy 8 bytes and the addresses are in the form of hexadecimal digits;
int main(){
    void *pnew; // creates a pointer of type void. Can take any data type.
    char c = 'a';
    pnew = &c;
    printf("The address of c is %p and it's value is %c\n", pnew, *(char *) pnew); // we have to type cast a void pointer when outputting it's results.
    int newday = 10;
    int *pnewday = NULL;
    pnewday = &newday;
    *pnewday += 10;
    printf("The address of pnewday is %p and it's value is %d\n", pnewday, *pnewday);
    int result=0;
    int number = 10;
    int *pmyman = &number;
    printf("The value of number is %d and it's address is %p\n", number, pmyman);
    printf("The address of the pointer itself is %p\n", &pmyman);
    printf("The value is pointed to: %d\n", *pmyman);
    result = *pmyman * 10; // using asterisk in a already-declared pointer variable dereferences it and gives back the value instead of it's address;
    int *presult = &result;
    printf("The value of result is %d and it's address is %p\n", result, presult);
    int man = ReturnFunc(21);
    printf("%d", man);
    char mystr[] = "The quick brown fox";
    char search_ch = 'q';
    char *GOT_CHAR = NULL;
    int *pnumber = &man;
    GOT_CHAR = strchr(mystr, search_ch);
    //printf("THe address of q is %s", GOT_CHAR);
    printf("The value of Multiply function is: %d\n", Multiply(20, 10));
    printf("The address of int man is : %p", pnumber);
    return 0;
}

int Multiply(int x, int y){
    int result = x*y;
    return result;
}


