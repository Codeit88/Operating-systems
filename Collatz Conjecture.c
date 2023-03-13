#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdbool.h>
int main(int argc,char*argv[]){
int fd1[2],fd2[2];
pipe(fd1);
pipe(fd2);
int starter=atoi(argv[1]);
int checker=0,returner=starter;
while(returner>1){
if(fork()>0){
//starter=returner;
close(fd1[0]);
close(fd2[1]);
write(fd1[1],&starter,sizeof(int));
wait(NULL);
read(fd2[0],&returner,sizeof(int));
if(returner==1)break;
close(fd1[1]);
close(fd2[0]);
}
else{
close(fd1[1]);
close(fd2[0]);
read(fd1[0],&checker,sizeof(int));
if(checker==1)exit(0);
else if(checker%2==0){
checker=checker/2;
printf(" %d \n",checker);
write(fd2[1],&checker,sizeof(int));
}
else if (checker%2!=0){
checker=(3*checker)+1;
printf(" %d \n",checker);
write(fd2[1],&checker,sizeof(int));
}
close(fd2[1]);
close(fd1[0]);
}
}
return 0;
}
