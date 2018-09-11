#include<stdio.h>
#include<stdlib.h>

int* allocateArray(int size,int value){
   int *arr = (int*) malloc(size*sizeof(int));
   for(int i= 0; i < size; i++){
           arr[i] = value;
   }
  return arr;
}

void main(){
  
   int *array;

   array = allocateArray(10,56);

   for(int i = 0; i<10;i++){
        printf("%d\n",array[i]);
   }
}
