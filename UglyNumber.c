/* ugly number */


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

int total;                         //to count toal ugly number in range
int *arr;                          //used when user want to check more than one number's
int size;                          //array size declared by the user.....

void check(unsigned long);
void options();
void operation(int);
char getch();                      //this function is copied.....to implement getch in linux or unix....
void createArray();

void main(){
    int num,i;
    

    while(1){
    system("clear");
    total = 0;
    
    options();
    }

}

void options(){
   int choice;

   printf("\nChoose operation that you want to perform...........\n");
   printf("\n1.Number of ugly number in provided range");
   printf("\n2.Whether the number is ugly or not");
   printf("\n3.Check the big set of number for ugliness");
   printf("\n4.n'th ugly number");
   printf("\n5.exit");
   printf("\nyour choice ");
   scanf("%d",&choice);

   operation(choice);
}

void operation(int choice){
    int i;
    int temp;
    int start,end;
    unsigned long num;
 
    system("clear");  

    switch(choice){

           case 1:
                 printf("\nEnter the starting point and ending poing with spaces in between ");
                 scanf("%d%d",&start,&end);
               
                 /*printf("\nEnter the ending point ");
                 scanf("%d",&end);*/


                 /*if user are crazy let be intelligent.....*/ 
                 if(start>end){
                        temp = start;
                        start = end;
                        end = temp;
                 }

                 for(i = start;i<=end;i++){
                        check(i);
                 }

                 printf("\nThere are %d of ugly number in range %d to %d",total,start,end);
                 break;


         case 2:
                printf("\nEnter the number to check ");
                scanf("%d",&num);

                check(num);

                if(total != 0)
                      printf("\n%ld is an ugly number",num);
                else
                      printf("\n%ld is not an ugly number",num);
               
                break;

        case 3:
              createArray();
              printf("\nProvide number's ....\n");
              for(i=0;i<size;i++)
                       scanf("%d",&arr[i]);

              for(i=0;i<size;i++)
                        check(arr[i]);

              printf("\nThere are %d ugly number in the given set",total);
              free(arr);
              arr = NULL;
              break;

        case 4:
              printf("\nEnter the value of n ");
              scanf("%d",&temp);

              i = 1;

              while(total!=temp){
                   check(i);
                   i++;
              }

              printf("\n%d",--i);
              break; 
          
        case 5:
              exit(0);
 
         default:
                printf("\n!!Choose only from the given operation....!");
       }

       getch();
}             

void check(unsigned long num){

    if(num<=0)
         return;
    

    if(num%2==0){
            check(num/2);
    }else if(num%3==0){
             check(num/3);
    }else if(num%5==0){
             check(num/5);
    }else if(num==1){
            total++;
    }
     else
        return;
}

void createArray(){


     printf("\nEnter the total number you want to check ");
     scanf("%d",&size);

     arr = malloc(sizeof(int)*size);    
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


