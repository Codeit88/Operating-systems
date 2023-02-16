#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main(int argc,char*argv[]){
int currsize=argc-1;
int arr[currsize];
int i=0,j=0;
for(i=0;i<currsize;i++){
arr[i]=atoi(argv[i+1]);
}
pid_t p=fork();
if(p==0){
for(i=0;i<currsize;i++){
for(j=i+1;j<currsize;j++){
if(arr[j]<arr[i]){
int temp=arr[j];
arr[j]=arr[i];
arr[i]=temp;
}
}
}
for(i=0;i<currsize;i++){
printf(" %d\n",arr[i]);
}
printf("My parent's id is %d\n",getpid());
}
printf("My id is %d\n",getpid());
}
