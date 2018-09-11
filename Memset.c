#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
  int *pi = malloc(5*sizeof(int));

  memset(pi,0,5*sizeof(int));

  printf("%d",*pi);
}
