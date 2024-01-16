#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

int main(){
	int ch;
	
	
	printf("Enter your choice : \n1]fork \n2]cp command \n3]execl command \n4] grep command");
	scanf("%d",&ch);
	
	switch(ch){
	
		case 1:{
		pid_t pid;
	
		pid=fork();
		int STATUS;
		if(pid==0){
		printf("I am the child");
		printf("i am the child process PID=%d",getpid());
		}
		
		if(pid>0){
			printf("i am the parent and pid is %d \n",getpid());
			pid=wait(&STATUS);
			printf("end of process %d \n",pid);
	
			if(WIFEXITED(STATUS)){
			printf("The process ended with exit(%d)\n",WEXITSTATUS(STATUS));
	
	
		}
		if(WIFSIGNALED(STATUS)){
		printf("the process  ended with kill = %d \n",WTERMSIG(STATUS));
	
		}
		}
	
	
	
		if(pid<0){
		perror("in fork():");
		}
		
		
		break;
		}
		
		
		case 2:{
		
			char **argv;
			argv[1]="cp";
			argv[2]="file1.txt";
			argv[3]="file2.txt";
			
			
			if(strcmp(argv[2],argv[3])!=0){
	
			char fs[100];
	
			FILE *fptr;
	
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
			break;
		
			}
			case 3:
			{
			execl("/bin/ls", "cp", "", "/home/pccoe/Desktop",(char *)0);
			break;
			}
	
			case 4:
			{
				char **argv;
				argv[1]="grep";
				argv[2]="-c";
				argv[3]="saurabh";
				argv[4]="file1.txt";
				
				int argc=4;
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
				
				break;
			}
		
		
	}
	
}
