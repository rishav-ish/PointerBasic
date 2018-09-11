#include<stdio.h>
#include<stdlib.h>

void main(){
  int *p1 = malloc(sizeof(int));
  *p1 = 5;

  int *p2;
  p2 = p1;

  free(p1);

  *p2 = 10;

   printf("%d",*p2);
}
