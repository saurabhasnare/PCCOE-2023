#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(void){

	pid_t pid;
	
	pid=fork();
	int STATUS;
	if(pid==0){
	printf("I am the child");
	printf("i am the child process PID=%d",getpid());
	execl("/bin/ls", "ls", "-l", "/home/pccoe/Desktop",(char *)0);
	perror("in exec(): ");
	
	
	
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
	exit(0);
	
}
