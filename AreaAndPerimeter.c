#include<stdio.h>
#include<stdlib.h>

void AreaAndPeri(float, float *,float*);

void main(){
  float radius;
  float area,perimeter;

  printf("Please enter the radius of circle ");
  scanf("%f",&radius);

  AreaAndPeri(radius,&area,&perimeter);

  System("clear");

  
