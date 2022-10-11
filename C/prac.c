#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int a(void);

int main(void){
  a();
  return 0;
}

int a(void){
  int num = 10;
  printf("The address of 'num' is %p\nThe value of num is %i", &num, num);
}
