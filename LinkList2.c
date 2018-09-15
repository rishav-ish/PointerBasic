#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<termios.h>

int lock = 0;

typedef struct  _people{
   char name[100];
   int age;
   float salary;
   struct _people *link;
}People;

void writefile(People *);
void append(People **);
void display(People *);
char getch();

void options(){
     printf("\nPlease choose from the following...");
     printf("\n1.Append List");
     printf("\n2.Display List");
     printf("\n3.Write Result to file");
     printf("\n4.exit");
     printf("\nyour choice ");
}

void main(){
   
     int choice,i,node_size;
     People *people = NULL;
    
  
     system("clear");

     while(1){
     options();

     scanf("%d",&choice);

     switch(choice){
        case 1:
              //system("clear");
              printf("\nEnter the number of link node you want to create ");
              scanf("%d",&node_size);

              system("clear");

              for(i = 0;i<node_size;i++){
                       
                        printf("\nPerson %d",i+1);
                         append(&people);
 			 system("clear");
             }

              printf("\nYour link list is created ...\n");
             // display(people);
 
              break;

       case 2:
             system("clear");
             display(people);
             system("clear");
             break;

       case 3:
             system("clear");
             writefile(people);
             break;

       case 4:
              system("clear");
              exit(0);
           

       default:
              system("clear");
              printf("\nPlease choose only from the given options");

    }
  }
}
    

void append(People**people){

       People *temp,*nextNode;

      
       if(*people==NULL){
             *people = malloc(sizeof(People));

              temp = *people;

              printf("\nEnter your name ");
              scanf("%99s",temp->name);

              printf("Enter your age ");
              scanf("%d",&temp->age);


              printf("Enter your salary ");
              scanf("%f",&temp->salary);

          
              temp->link = NULL;
              lock = 1;
       }else{

            temp = *people;

            while(temp->link!=NULL)
                     temp = temp->link;

            nextNode = malloc(sizeof(People));


            temp->link = nextNode;

            printf("\nEnter your name ");
            scanf("%99s",nextNode->name);

            printf("Enter your age ");
            scanf("%d",&nextNode->age);


            printf("Enter your salary ");
            scanf("%f",&nextNode->salary);

            nextNode->link = NULL;
     }

    
}

void display(People *people){
      int user;

     if(lock == 1){

      while(people!=NULL){
               printf("\n%s\nAge %d\nSalary %.2f\n",people->name,people->age,people->salary);
               people = people->link;
     }
   }else
       printf("\nFirt initialize link list");
     printf("\nPress any button ");
     getch();
}


void writefile(People *people){
   FILE *file;
   char url[100];

   if(lock==0) 
          return;

   printf("\nEnter file name ");
   scanf("%s",url);


   file = fopen(url,"w");

   while(people!=NULL){
       fprintf(file,"%s\nAge %d\nSalary %.2f\n",people->name,people->age,people->salary);
       people = people->link;
  }

  fclose(file);
}

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
