
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(){

	int pid;
	int i;

	i = 1000;

	pid = fork();

	if(pid == -1){

		perror("fork error");
		exit(0);

	}

	else if(pid == 0){
		printf("자식프로세스는 %d \n", pid);
		while(1)
		{
			printf("-->%d\n", i);
			i++;
			sleep(1);
		}

	}else{
		printf("부모 : 내가 낳은 자식의 pid = %d\n",pid);
		sleep(1);
		printf("T.T 나죽네 \n");
		exit(0);
		
	}


	return 0;
}
