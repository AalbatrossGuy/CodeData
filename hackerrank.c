#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int one(int a, int b, int c, int d){
    int max = 0;
    
    if(max <= a) max = a;
    if(max <= b) max = b;
    if(max <= c) max = c;
    if(max <= d) max = d;
    return max;  
}


int main(){
    int ans = one(10, 20, 50, 5);
    printf("%d\n", ans);
    return 0;
}
