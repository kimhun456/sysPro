


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){

	int pid;
	int i;

	i = 1000;

	pid = fork();

	if(pid == -1){
		perror("fork Error");
		exit(0);
	}

	else if(pid == 0){
		printf("¿¿ ¿¿¿¿¿ pid = %d", pid );
		while(1){
			printf("--->%d\n", i);
			i++;
			sleep(1);
		}
	}
	else{

		printf("¿¿ ¿¿¿¿¿  pid  = %d",pid);

		while(1){
				printf("--->%d\n", i);
			i+=4;
			sleep(1);
		

		}
	}


}
