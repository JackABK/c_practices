 /*=============================================================================
  *
  * @file     : fork.c
  * @data     : 2014/2/6
  * @author   : JackABK
  * @brief    : fork practice 
  *
  *============================================================================*/

#include <stdio.h> 
#include <unistd.h>
main () 
{ 
		pid_t fpid;
		fpid=fork(); 

		if (fpid < 0)  /*error occurred.*/
				printf("fail in fork!"); 
		else if (fpid == 0) { /*child process.*/
				child_process(fpid);
		}
		else { /*parent process.*/
				parent_process(fpid);
		}
}
void child_process(int fpid){
		printf("======================Child Process======================\n");
		printf("My PID is %d\n",getpid()); 
		printf("=========================================================\n\n");
}
void parent_process(int fpid){
		printf("======================Parent Process======================\n");
		printf("My PID is %d\n",getpid()); 
		printf("My child PID is %d\n",fpid);
		printf("==========================================================\n\n");
}
