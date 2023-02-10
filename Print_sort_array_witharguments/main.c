
#include"header.h"

void main(int argc,char*argv[]){
int size=argc-3;
int arr[size];
int i=0;
printf("sasa\n");
for(i=0;i<size;i++){
arr[i]=atoi(argv[i+1]);
}
sort(arr,size,3);
print(arr,size);

printf("sasa\n");
high(arr,size,4);
return;
}
