#include<stdio.h>
#include<stdlib.h>

void main(){
  int num = 16;

  int *ptr = &num;

  printf("Address of pointer: %x\n",ptr);
  printf("value %d",*ptr);

  free(ptr);

  printf("Address of pointer: %x\n",ptr);
  printf("value %d",*ptr);
}
