

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
		printf("자식 : 내 pid = %d\n", getpid());

		close(0);
		close(1);
		close(2);
		setsid();
		while(1)
			        {
						            printf("-->%d\n", i);
									            i++;
												            sleep(1);
															        }



	}else{
		printf("부모 : my chlid %d\n",pid);

		sleep(1);
		printf("i'm dead\n");

		exit(0);


	}

}
