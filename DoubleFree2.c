#include<stdio.h>
#include<stdlib.h>

void main(){
   int *p1 = (int*) malloc(sizeof(int));
   int *p2 = p1;

   *p1 = 5;

    free(p1);
    free(p2);
}   
