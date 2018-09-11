#include<stdio.h>

int (*fptr1)(int);

int square(int num){
   return num*num;
}

void main(){
   int n = 5;
   fptr1 = square;  //can also use &square but compiler will ignore it....
   
   printf("%d sqaure is %d\n",n,fptr1(n));
}
