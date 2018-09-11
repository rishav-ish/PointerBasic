#include<stdio.h>

int add (int num1,int num2){
    return num1+num2;
}

int sub(int num1,int num2){
    return num1-num2;
}

typedef int (*fptrOperation) (int,int);

fptrOperation operations[128] = {NULL};

void arrayInitialize(){
operations['+'] = add;
operations['-'] = sub;
}

int evaluate(char opcode,int num1,int num2){
       fptrOperation operation = operations[opcode];
       return operation(num1,num2);
}

void main(){
    arrayInitialize();
    printf("%d\n",evaluate('+',5,6));
    printf("%d\n",evaluate('-',5,6));
}
