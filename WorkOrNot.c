#include<stdio.h>
#include<stdlib.h>

void main(){
  int i = 2254;
  float a = 3.14;
  char *ii, *aa;

  ii = (char*) &i;
  aa = (char*) &a;

  printf("Address contained in ii = %p\n",ii);
  printf("Address contained in aa = %p\n",aa);
  printf("Value at the address contained in ii = %d\n",*ii);
  printf("Value at the address contained in aa = %f\n",*aa);

}
