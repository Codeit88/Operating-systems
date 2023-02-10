#include <stdio.h>
int main(int argc,char*argv[]){
int a=atoi(argv[1])+atoi(argv[2])+atoi(argv[3]);
float avera=a/3;
printf("Sum is : %d \n",a);
printf("Average is : %f \n",avera);
return 0;
}
