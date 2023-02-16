#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc,char*argv[]){
int size=atoi(argv[1]);
int i=0;
pid_t p=fork();
if(p==0){
for(i=0;i<size;i++){
if(p==0){
printf("IDS Are %d %d \n",getpid(),getppid());
p=fork();
}
else{
wait(NULL);
}
}
}
else
wait(NULL);
}
