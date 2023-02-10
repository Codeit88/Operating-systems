#include"header.h"
void sort(int arr[],int size,int dir){
int i=0,j=0;
for(i=0;i<size;i++){
for(j=i+1;j<size;j++){
if(arr[i]>arr[j]){
int swap=arr[i];
arr[i]=arr[j];
arr[j]=swap;
}
}
}
}
void high(int array[],int size,int pos){
int i=0,j=0;
for(i=0;i<size;i++){
for(j=i+1;j<size;j++){
if(array[i]<array[j]){
int swap=array[i];
array[i]=array[j];
array[j]=swap;
}
}
}
printf("%d ",array[pos-1]);
}
void print(int array[],int size){
int i=0;
while(i<size){
printf("%d ",array[i]);
i++;
}
}
