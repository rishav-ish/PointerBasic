#include<stdio.h>
#include<malloc.h>
#include<string.h>

void main(){

   char *name = (char*) malloc(strlen("Susan")+1);

   strcpy(name,"Susan");

   while(*name != 0){
      printf("%c",*name);
      name++;
   }

   printf("\n");
   name--;

  while(*name!=0){
     printf("%c",*name);
     name--;
  }
}
