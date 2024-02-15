#include<assert.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
int main(){
	int fd[2],pid;
	int filedes=open("file1.txt",O_RDONLY);
 
	dup2(filedes,fileno(stdin));
	close(filedes);
	pipe(fd);
	pid=fork();
	if(pid==0){
	//child process
	dup2(fd[1],fileno(stdout));
	close(fd[0]);
	close(fd[1]);
	execl("/usr/bin/sort","sort",(char *) 0);	
	
	}else if(pid>0){
	//parent
	dup2(fd[0],fileno(stdin));
	close(fd[1]);
	close(fd[0]);
	execl("/usr/bin/uniq","uniq",(char *)0);
	
	}else{
	perror("fork");
	exit(1);
	}
}
