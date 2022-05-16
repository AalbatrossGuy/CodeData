#include <stdio.h>
#include <stdbool.h>

int main(){
    enum DaysOfWeek {Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};
    enum DaysOfWeek today = Friday;
    switch (today){
        case Monday:
            printf("Today is Monday");
            break;

        case Tuesday:
            printf("Today is Tuesday");
            break;
        
        case Wednesday:
            printf("Today is Wednesday");
            break;
        
        default:
            printf("Hi There");
            break;
    }
    return 0;   
}

