#include<stdio.h>
#include<stdlib.h>

int add(int num1, int num2){
     return num1+num2;
}

int sub(int num1,int num2){
     return num1-num2;
}

int mul(int num1,int num2){
    return num1*num2;
}

typedef int (*fptrOperation)(int, int);

fptrOperation evaluate(char opcode){
      switch(opcode){
          case '+':
               return add;
          case '-':
 	       return sub;
          case '*':
               return mul;
         // default:
	//	return NULL;
      }
}

int compute(char opcode,int num1,int num2){
       fptrOperation operation = evaluate(opcode);
       return operation(num1,num2);
}

void main(){
   int num1;
   int num2;
   int choice;
   char opcode;

   printf("\nPlease choose the operation you want to be performed");
   printf("\n1.Add");
   printf("\n2.Sub");
   printf("\n3.Mul");
   printf("\n4.Exit");
   printf("\nYour Choice ");
   
   scanf("%d",&choice);

   if(choice<1 || choice>4){
        printf("Please enter number as provided ");
        getchar();
        system("clear");
        main();
   }else if(choice==4){
          exit(0);
    }
    else {
       printf("\nPlease enter first number "); 
       scanf("%d",&num1);
     
       printf("\nPlease enter second number ");
       scanf("%d",&num2);

  switch(choice){
       case 1:
            printf("\n%d + %d = %d\n",num1,num2,compute('+',num1,num2));
            break;
       case 2:
            printf("\n%d - %d = %d\n",num1,num2,compute('-',num1,num2));
            break;
       case 3:
            printf("\n%d * %d = %d\n",num1,num2,compute('*',num1,num2));
    
   }
}	
}
