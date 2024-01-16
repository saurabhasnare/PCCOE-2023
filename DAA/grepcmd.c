#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
int main(int argc,char **argv){

	//arhiment syntax ./grep -c "name" file.txt;	
	//printf("file not exists or failed to open");
	
	char fs[100];
	FILE *fptr;
	fptr=fopen(argv[4],"r+");
	
	if(fptr){
		
		if(strcmp(argv[2],"-c")==0){
			
			int count=0;
			if(argc>=2){
			
				while(fscanf(fptr,"%s",fs)!=EOF){
					if(strcmp(argv[3],fs)==0){
						count++;
					}
				}
			}
			printf("count= %d",count);
			 
		}
	}
	else{
	
		printf("file not exists or failed to open");
	}
	
		//printf("file not exists or failed to open");
	fclose(fptr);
	return 0;
	
}

