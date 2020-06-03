#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
 
int main() 
{ 
/*
	fork(); 
	write(1, "Hello\n", strlen("Hello\n"));
	return 0; 
*/

	int id;
	id = fork();
	if(id == 0)
	{
		write(1, "I am the child process\n", strlen("I am the child process\n"));
		//printf("I am child process my ID is   =  %d\n" , getpid());
		printf("This is the priority of child process = %d\n", getpriority(PRIO_PROCESS, 0));
	}
	else
	{
		write(1, "I am parent process.\n", strlen("I am parent process.\n"));
		//printf("I am parent process.\n");
		printf("This is the priority of parent process = %d\n", getpriority(PRIO_PROCESS, 0));
	}
}

