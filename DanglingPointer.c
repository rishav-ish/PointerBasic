#include<stdio.h>
#include<stdlib.h>

void main(){
  
  int *pi = malloc(sizeof(int));
  
  *pi = 100;

   printf("Address %x",pi);
   printf("Current Value %d\n",*pi);

   free(pi);

   printf("%d\n",*pi);
 
   *pi = 200;

   printf("Addres %x",pi);	
   printf("New value %d",*pi);
}
