#include<stdio.h>
#include<stdlib.h>

void main(){
   int *pi = calloc(5,sizeof(int));

   printf("%d",*pi);
}
