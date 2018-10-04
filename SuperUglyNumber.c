#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>


//void initArray();
void options();
void operation(int);
void initSet();
void check(unsigned long);
void checkPrime();
char getch();

//int *arr;
int *set = NULL;
unsigned int /*size,*/setSize;
unsigned int total;


void main(){
 
   initSet();

    while(1){
       system("clear");
       total=0;
       options();
    }
    free(set);
    set = NULL;
}



void initSet(){
     unsigned int i;
     
     if(set!=NULL){
              free(set);
              set = NULL;
     }
     
     printf("\nEnter the size of set ");
     scanf("%d",&setSize);

     set = malloc(sizeof(int)*setSize);

     printf("\nEnter the set now (remember to provide prime)\n");

     for(i=0;i<setSize;i++)
               scanf("%d",&set[i]);

     checkPrime();
}


void options(){
    int choice;
    
    printf("\nChoose from the following operations.....\n");
    printf("\n1.Check whether the given number is super ugly or not");
    printf("\n2.Check the total number of super ugly number in given range");
    printf("\n3.n'th ugly number in given set");
    printf("\n4.Enter new set");
    printf("\n5.exit");
    printf("\nyour choice ");

    scanf("%d",&choice);
    operation(choice);
}


void operation(int choice){
      unsigned long num;
      int start,end,temp,i;
      
      system("clear");
 
      switch(choice){
           case 1:
                printf("\nEnter the number you want to check ");
                scanf("%d",&num);

                check(num);

                if(total==1)
                        printf("\n%ld is a super ugly number for the given set",num);
                else
                        printf("\n%ld is not an ugly number",num);

                break;

           case 2: 
		 printf("\nEnter the range with space in between start and end ");
                 scanf("%d%d",&start,&end);

                 if(start>end){
                       temp = start;
                       start = end;
                       end = temp;
                 }

                 for(i = start;i<=end;i++)
                             check(i);

                 printf("\nThere are %d super ugly number in range of %d to %d",total,start,end);

                 break;

             case 3:
                 printf("\nEnter the n'th number ");
                 scanf("%d",&temp);

                 i = 1;

                 while(total!=temp){
                      check(i);
                      i++;
                 }

                 printf("\nn'th number is %d",--i);
                 break;

             case 4:
                   free(set);
                   set = NULL;
                   initSet();
                   break;

           

             case 5:
	           exit(0);

             default:
                   printf("!!!...Enter only from the given operation..!");
          }

          getch();
}	

/*void initArray(){
  printf("\nEnter the total set of number's ");
  scanf("%d",&size);

  arr = malloc(sizeof(int)*size);
}*/


void check(unsigned long num){
     int i = 0;

      while(i<setSize){
           if(num==1){
                 total++;
                 //printf("\n%d %d",num,total);
                 return;         
           }

           else if(num%set[i]==0){
                   //printf("\n%d",num);
                   check(num/set[i]);
                   return;

           }

           i++;
    }

}

void checkPrime(){
      int i = 0,j;
      int flag = 0;

     while(i<setSize){

      for(j=2;j<=set[i]/2;j++){
               if(set[i]%j==0){
                     flag = 1;
                     printf("\n%d is not a prime number",set[i]);
                     break;
               }
      }
      i++;
    }

    if(flag==1){
          printf("\nPlease reinitialize your set with proper value .....");
          getch();
          initSet();
    }

}


//Copy code for implementation of getch function......

char getch(){
    /*#include <unistd.h>   //_getch*/
    /*#include <termios.h>  //_getch*/
    char buf=0;
    struct termios old={0};
    fflush(stdout);
    if(tcgetattr(0, &old)<0)
        perror("tcsetattr()");
    old.c_lflag&=~ICANON;
    old.c_lflag&=~ECHO;
    old.c_cc[VMIN]=1;
    old.c_cc[VTIME]=0;
    if(tcsetattr(0, TCSANOW, &old)<0)
        perror("tcsetattr ICANON");
    if(read(0,&buf,1)<0)
        perror("read()");
    old.c_lflag|=ICANON;
    old.c_lflag|=ECHO;
    if(tcsetattr(0, TCSADRAIN, &old)<0)
        perror ("tcsetattr ~ICANON");
    printf("%c\n",buf);
    return buf;
 }





