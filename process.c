#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
//#include "hanoi.h"

int count = 0;

int main(){
	pid_t fork_ret;
	pid_t child;
//	int local_val = 0;
	int state;

	fork_ret = fork();
	fork_ret = fork();
	fork_ret = fork();
	fork_ret = fork();

	if(fork_ret < 0){
		printf("fork() error\n");
		exit(1);
	}
	else if(0==fork_ret){
//		global_val++;
//		local_val++;
		hanoi('A', 'B', 'C', 3);
		printf("CHILD - PID : %d parent's PID : %d \n", getpid(), getpid());
	}
	else{
//		global_val = global_val + 5;
//		local_val = local_val + 5;
		printf("PARENT - PID : %d child's PID : %d \n", getpid(), fork_ret);

		child = wait(&state);
		printf("\t Child PID = %d \n", child);
//		printf("\t return value = %d \n", WEXITSTATUS(state));

//		sleep(10);
	}
	
//	printf("\t global_val : %d \n", global_val);
//	printf("\t local_val : %d \n", local_val);

	return 0;
}

void hanoi(char from, char temp, char to, int n){
	if(n==1){
		++count;
		printf("%5d: From %c to %c disk %d\n", count, from, to, 1);
	}
	else{
		hanoi(from, to, temp, n-1);
		++count;
		printf("%5d: From %c to %c disk %d\n", count, from, to, n);
		hanoi(temp, from, to, n-1);
	}
}
