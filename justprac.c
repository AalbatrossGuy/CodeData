#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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

int ReturnFunc(int x){
    int res = x+20.13;
    return res;
}

int main(){
    int man = ReturnFunc(21);
    printf("%d", man);
    char mystr[] = "The quick brown fox";
    char search_ch = 'q';
    char *GOT_CHAR;
    GOT_CHAR = strchr(mystr, search_ch);
    printf("THe address of q is %s", GOT_CHAR);
    return 0;
}
