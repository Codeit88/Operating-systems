#include<stdio.h>
int main(int argc,char *argv[]){
FILE*input=fopen(argv[1],"r");
FILE*output=fopen(argv[2],"w");
char c=fgetc(input);
while(c!=EOF){
fputc(c,output);
c=fgetc(input);
}
return 0;
}
