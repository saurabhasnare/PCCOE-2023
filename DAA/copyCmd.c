#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(int argc,char **argv){

	
	if(strcmp(argv[2],argv[3])!=0){
	
	char fs[100];
	
	FILE *fptr;
	//execl("/bin/ls", "cp", "", "/home/pccoe/Desktop",(char *)0);
	fptr=fopen(argv[2],"r+");
	
	if(fptr){
	
		FILE *fn=fopen(argv[3],"r+");
		
		while(fscanf(fptr,"%s",fs)!=EOF){
		
		fprintf(fn,"%s\n",fs);
		
		}
	}else{
		printf("\nOpps.. file does not exist or failed to open..");
	}
		fclose(fptr);
	}else{
		printf("\n source and destination files are same\n");
	}
	return 0;
}
