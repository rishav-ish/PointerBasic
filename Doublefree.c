//It will probably result in runtime exception but here goes nothing...

#include<stdio.h>
#include<stdlib.h>

void main(){

   int *pi = (int*) malloc(sizeof(int));
   *pi = 5;

    free(pi);
   
    printf("%d\n",*pi);
   
    free(pi);

    printf("%d\n",*pi);
}
