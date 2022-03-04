#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int prob_one(int num);

int main(void){
    int x = prob_one(10564);
    printf("%d", x);
    return 0;
}

int prob_one(int num){
    int sum;
    sum += (num%10);
    return sum
}