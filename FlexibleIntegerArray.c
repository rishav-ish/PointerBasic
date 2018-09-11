#include<stdio.h>
#include<stdlib.h>

int * array;
int array_size;
int lock = 0;

void initializeArray();
void increaseArraySize();
void decreaseArraySize();
void display();
void bubbleSort();
void linearSearch();
void wait();


void choices(){
     system("clear");
     printf("\nPlease select from the following.........\n");
     printf("\n1.Initialize Array");
     printf("\n2.Increase Array Size");
     printf("\n3.Decrease Array Size");
     printf("\n4.Bubble Sort");
     printf("\n5.Insertion Sort");
     printf("\n6.Linear Search");
     printf("\n7.Binary Search");
     printf("\n8.Display Array");
     printf("\n9.Exit");
     printf("\nYour choice ");
}


void main(){
     int choice;
     
      choices();

      scanf("%d",&choice);

      switch(choice){
         case 1:
              initializeArray();
              break;

         case 2:
              //increaseArraySize();
              if(lock==1){
                  increaseArraySize();
                  main();
              }else{
                printf("\nInitialize Array before increasing the size....");
                initializeArray();
             }
              break;
	
         case 3:
              decreaseArraySize();
              wait();
              main();
	      break;
         
         case 4:
              bubbleSort();
              wait();
              main();
              break;
       /*
         case 5:
              insertionSort();
              break;
       */
         case 6:
              linearSearch();
              wait();
              main();
              break;
        /*
         case 7:
              binarySearch();
              break;
        */

         case 8:
              display();
              wait();
              //getchar();
               main();

         case 9:
              system("clear"); 
              exit(0);


         default:
               system("clear");
               printf("\nPlease choose only from the given option....\n");
               wait();
               main();
      }
 }


 void initializeArray(){
     // int *array;
      int  i;
      
      system("clear");      

      if(array!=NULL) free(array);

      printf("\nEnter the array size ");
      scanf("%d",&array_size);


      array = malloc(sizeof(int)*array_size);

      for(i = 0 ; i<array_size; i++){
               printf("\narray[%d] = ",i+1);
               scanf("%d",&array[i]);
     }

     lock = 1;

     system("clear");
     printf("\nArray is successfuly initialized \n");
     main();
}


void increaseArraySize(){
    int increaseSize;
    printf("\nEnter the size by which you want to increase the array ");
    scanf("%d",&increaseSize);

    array_size += increaseSize;

    array = realloc(array,array_size);

    printf("\nArraySize is successfuly increased....\n");

    
}  

void decreaseArraySize(){
     int decrease;
     printf("\nEnter the size by which you want to decrease the array ");
     scanf("%d",&decrease);

     array_size-=decrease;

     array = realloc(array,array_size);
     printf("\nArraySize is successfuly decreased...\n");
}

void display(){
    int i;

    system("clear");

    for(i=0;i<array_size;i++){
         printf("\n%d",array[i]);
    }


   // system("clear");
}

void bubbleSort(){
   int i,j,temp;

    for(i= 0;i<array_size;i++){
          for(j=0;j<array_size-i;j++){
                    
                     if(array[j] > array[j+1]){
                               temp = array[j];
                               array[j] = array[j+1];
                               array[j+1] = temp;
                     }
	    }
     }

     printf("\nArray is sorted...\n");
     
}


void linearSearch(){
   int num;
   int i;
   int flag = 0;

   system("clear");
   printf("\nEnter the number you want to search in an array ");
   scanf("%d",&num);

   for(i = 0; i<array_size;i++){
            if(num==array[i]){
                  flag = 1;
                  break;
            }
   }

   if(flag==1){
        printf("\n%d is in array",num);
   }else{
        printf("\nSorry, %d is not in array",num);
  }

  //getchar();
}

void wait(){
    char character;
    
    printf("\nPress any key...");
    character = getchar();
}
