#include<stdio.h>

int main() {
    int length, width, area;
    printf("Enter the Length of the rectangle:\n");
    scanf("%d", &length);
    printf("Enter the width of the rectangle:\n");
    scanf("%d", &width);
    area = length*width;
    printf("The area is: %d\n", area);
    return 0;
}
