#include <stdio.h>
#include <unistd.h>

int data = 10;

void child_process()
{
	printf("Child process %d, data %d\n", getpid(), data);
	data = 20;	//page fault
	printf("Child process %d, data %d\n",getpid(), data);
	//_exit(0);
	while(1);
}

int main(int argc,char *argv[])
{
	int pid;
	
	//1.写时不拷贝
	//2.阻塞的
	pid = vfork();
	
	if(-1 == pid)
		exit(-1);
	
	if( 0 == pid)
	{
		child_process();
	}
	else
	{
		sleep(1);
		printf("Parent process %d, data %d\n",getpid(), data);
	}
	return 0;
}