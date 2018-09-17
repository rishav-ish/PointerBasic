#include<stdio.h>
#include<stdlib.h>


void main(){
  
      FILE *in;
      FILE *out;
      char line[500];
      char url[200];
      char url2[200];

      printf("\nEnter the file name ");
      scanf("%s",url);

      in = fopen(url,"r");

      if(in==NULL){
          printf("\nUnable to open file");
          return;
      }

      printf("\nEnter the file name you want me to save it in ");
      scanf("%s",url2);

      out = fopen(url2,"w");

      //out = fopen("temp.txt","w");

      while(fscanf(in,"%[^\n]\n",line)==1){

            fprintf(out,"\necho %s",line);
      }
}

 
