#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
	printf("In parent process before fork \n");  // the \n is imp so that the buffer is flushed and not passed to child
    int x;                                           // cuz output to terminal is line buffered
	if ( (x=fork())==0)
	{
                                
               printf("In child process now pid=%d \n",getpid()); // \n is necessary else exec will be called b4 buffers are flushed
                execl("./yolo.out",(char *)0);
               // execl("/bin/date","date",); //execl uses file,arg0,arg1 format.the arguments must terminated by NULL 
                
                printf("this line will not be printed \n");//since exec completely overwrites calling process
                sleep(100);
                exit(0);
		
		
	}
	else
	{
                //wait() is necesaary without which child process becomes zombie
		wait(NULL); //NULL in wait() => we are not interested in exit status
		printf("parent pid=%d \n",getpid());
		printf("task completed \n");
                sleep(100);
		
	}
}