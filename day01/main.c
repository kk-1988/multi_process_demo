#include <stdlib.h>
#include <stdio.h>

void exit1print(void)
{
	printf("hello exit1\n");
}

void exit2print(void)
{
	printf("hello exit2\n");
}

int main(int argc,char *argv[])
{
	atexit(exit1print);
	atexit(exit2print);
	
	printf("hello main enter\n");
	return 0;
}