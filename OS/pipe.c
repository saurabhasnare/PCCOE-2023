//pipe dup2 

//imp syscall

#include<stdio.h>
#include<unistd.h>

int main(){

	int pipefds[2];
	char writemessages[2][20]={"hiee" , "hello"};
	
	char readmessage[20];
	int returnstatus=pipe(pipefds);
	
	if(returnstatus==-1){
		printf("unable to create pipe\n");
		return 1;
	}
	
	int pid = fork();
	   if (pid == 0) {
	   	printf("child writing to pipe -message 1 is %s\n",writemessages[0]);
		write(pipefds[1],writemessages[0],sizeof(writemessages[0]));
		read(pipefds[0],readmessage,sizeof(readmessage));
	
		printf("child reading from pipe-message 2 is %s\n",readmessage);
	   }
	   else{
	   	printf(" Parent writing to pipe -message 2 is %s \n",writemessages[1]);
		write(pipefds[1],writemessages[1],sizeof(writemessages[1]));
		read(pipefds[0],readmessage,sizeof(readmessage));
		printf("Parent reading from pipe-message  2 is %s\n",readmessage);
	   }
	return 0;
		
}



