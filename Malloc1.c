#include<stdio.h>
#include<stdlib.h>

void main(){
 
  char *name = (char*) malloc(10);

  if(name!=NULL){
       printf("Please enter your name ");
       scanf("%s",name);

       printf("Hello %s",name);
  }else{
    printf("Sorry Something is wrong please try after some time");
  }
}
