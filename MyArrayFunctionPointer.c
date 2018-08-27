#include<stdio.h>
#include<stdlib.h>

int add(int num1,int num2){
      return num1+num2;
}

int sub(int num1,int num2){
      return num1*num2;
}

int mul(int num1,int num2){
      return num1*num2;
}

typedef int (*fptrOperation) (int, int);

fptrOperation operations[128] = {NULL};

void InitializeArray(){
     operations['+'] = add;
     operations['-'] = sub;
     operations['*'] = mul;
}

int compute(char opcode,int num1,int num2){
     fptrOperation operation = operations[opcode];
     return operation(num1,num2);
}

void main(){
   int num1, num2,choice;
   
   system("clear");
 
   printf("\nPlease enter choose from the given options");
   printf("\n1.Addition");
   printf("\n2.Subtraction");
   printf("\n3.Multiplication");
   printf("\n4.Exit");
   printf("\nPlease enter your choice ");
   scanf("%d",&choice);

   if(choice >=1 && choice <=4){
         if(choice==4){
                exit(0);
          }

       InitializeArray();
       printf("\nPlease enter first number ");
       scanf("%d",&num1);
      
       printf("\nPlease enter second number ");
       scanf("%d",&num2);
        
       switch(choice){
            case 1:
                  printf("\n%d + %d = %d",num1,num2,compute('+',num1,num2));
                  break;
    
            case 2:
		  printf("\n%d - %d = %d",num1,num2,compute('-',num1,num2));
                  break;
 
            case 3:
                   printf("\n%d * %d = %d",num1,num2,compute('*',num1,num2));
          }

          getchar();
     }else{
         printf("\nPlease enter the input from the give input");
         printf("\nClick any key.....");
         getchar();
         system("clear");
         main();
    }
}
      
