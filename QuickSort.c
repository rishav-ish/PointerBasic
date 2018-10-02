#include<stdio.h>
#include<stdlib.h>

void quicksort(int,int);
int partition(int,int);
void swap(int,int);

int *arr;

void main(){
   int arraySize;
   int i;

   printf("\nEnter the size of array ");
   scanf("%d",&arraySize);

   arr = malloc(sizeof(int)*arraySize);

   for(i = 0;i<arraySize;i++)
            scanf("%d",&arr[i]);

   quicksort(0,arraySize-1);

   printf("\nHere is your soted list......\n");

   for(i = 0;i<arraySize;i++)
              printf("\t%d",arr[i]);
        
   printf("\n");
}

void quicksort(int start,int end){
     int pIndex;
    
     if(start<end){
            pIndex = partition(start,end);
            quicksort(start,pIndex-1);
            quicksort(pIndex+1,end);
     }
}

int partition(int start,int end){ 
      int pivot = arr[end];
      int i;
      int pIndex = start;
      int temp;

      for(i=start;i<end;i++){
            if(arr[i]<=pivot){
                   swap(i,pIndex);
                   pIndex++;
            }
      }

      swap(i,pIndex);

      return pIndex;
}


void swap(int index1,int index2){
     int temp;

     temp = arr[index1];
     arr[index1] = arr[index2];
     arr[index2] = temp;
}

     
