#include<stdio.h>
#include<stdlib.h>

void swap(int*,int*);

void main(){
   int a,b;

   printf("Please enter first number ");
   scanf("%d",&a);

   printf("Please enter second number ");
   scanf("%d",&b);

   swap(&a,&b);

   printf("Swaping.....\n");
   printf("%d\n%d\n",a,b);
   getchar();
}

void swap(int *a,int*b){
   int t;

   t = *a;
   *a = *b;
   *b = t;
}
