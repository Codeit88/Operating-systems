#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc,char*argv[]){

system("clear");
printf("......................Welcome to My Shell....................\n ");



top:char str[100];                            //this will recall the function
   printf( " Enter a new command : ");
   scanf("%s", str);
 
 
 //counting words of string
int len=1,p=0;
while(str[p]!='\0'){
if(str[p]==',')
len++;
p++;
}


//tokenizing the string and storing it in array
 char dyna[len][10];
   char *token;
    int i=0,k=0,j=0;
   token = strtok(str,",");
   while( token != NULL ) {
      printf( " Token is : %s \n", token );
      for(i=0;i<10;i++){
      dyna[k][i]=token[i];
   if(!token[i]){
  	dyna[k][i] = '\0';
   break;
   }
      }
      token = strtok(NULL,",");
      k++;
   }
   
   
//initiating fork to call the passed command
 if(fork()<1){
char*arr2[len+1];
int l =0;
for(l = 0; l<len;l++)
	arr2[l] = dyna[l];
 arr2[len] = NULL;
execvp(dyna[0], arr2);
}
wait(NULL);


//waiting for exit() call
if(!strcmp(dyna[0],"exit"))
system("exit");
else
goto top;

return 0;
}
