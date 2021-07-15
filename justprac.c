#include <stdio.h>
#include <stdbool.h>

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
    return 0;
}
