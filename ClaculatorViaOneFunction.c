#include<stdio.h>

int add(int num1, int num2){                    //addition function
    return num1+num2;
}

int subtract(int num1,int num2){               //subtraction function
    return num1-num2;
}

int divide(int num1,int num2){		//division function
    return num1/num2;
}

int multiply(int num1,int num2){		//multiplication function
    return num1*num2;
}

typedef int (*fptrCompute)(int,int);	//function pointer declaration

int calculate(fptrCompute compute,int num1,int num2){  //compute function 
       return compute(num1,num2);                      // declaration
}

void main(){                                          //main code
   printf("\nAddition %d",calculate(add,5,6));
   printf("\nSubtraction %d",calculate(subtract,5,6));
   printf("\nDivide %d",calculate(divide,5,6));
   printf("\nMultiply %d",calculate(multiply,5,6));
}
