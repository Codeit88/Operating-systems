#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<sys/time.h>

//#include <time.h>

#include <unistd.h>
int main(int argc,char*argv[]){
  struct timeval current_time;
  long int d1,d2;
  gettimeofday(&current_time, NULL);
  printf("Start Micro seconds : %ld \n",
  current_time.tv_usec);
d1=current_time.tv_usec;
if(fork()==0){
system(argv[1]);
}
else{
  wait(NULL);
  gettimeofday(&current_time, NULL);
  printf("End Micro seconds : %ld \n",
  current_time.tv_usec);
  d2=current_time.tv_usec;
  printf("Elapsed time is  : %li \n",
  d2-d1);
  
}
return 0;
}

