#include<stdio.h>

void main(){
   int matrix[2][3] = {{1,2,3},{4,5,6}};
  
   for(int i = 0;i<2;i++){
       printf("\n&matrix[%d]: %p sizeof(matrix[%d]): %d\n",i,&matrix[i],i,sizeof(matrix[i]));
}
}
