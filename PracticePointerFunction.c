#include<stdio.h>

int (*funct) (int);

int square(int number){
    return number*number;
}

void main(){
   int number;

   printf("Please enter a number ");
   scanf("%d",&number);

   funct = square;

   printf("\n%d square is %d",number,funct(number));
}
