#include<stdio.h>
#include<stdlib.h>

void main(){
 
   int *pi = malloc(sizeof(int));

   *pi = 20;

   printf("Address value: %x\n",pi);
   printf("Values at pointer: %d\n",*pi);
  
   free(pi);                      //Dangling pointer....

   printf("Address value: %x\n",pi);
   printf("values at pointer: %d\n",*pi);
}
