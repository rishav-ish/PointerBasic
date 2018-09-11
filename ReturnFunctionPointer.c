#include<stdio.h>

int add(int num1,int  num2){
   return num1 + num2;
}

int subtract(int num1, int num2){
    return num1 - num2;
}

typedef int (*fptrOperation)(int ,int);

fptrOperation evaluate(char opcode){
     switch(opcode){
          case '+':
               return add;

	  case '-':
               return subtract;
}
}
     

int compute(char opcode,int num1, int num2){
    fptrOperation operation = evaluate(opcode);
    return operation(num1,num2);
}

void main(){
   printf("%d\n",compute('+',5,6));
   printf("%d\n",compute('-',5,6));
}
