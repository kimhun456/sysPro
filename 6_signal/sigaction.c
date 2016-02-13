#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char **argv){

	sigset_t sigset;
	sigset_t pendingset;

	int i = 0;

	// 모든 시그널에 대해서 block한다. 

	sigfillset(&sigset);
	sigprocmask(SIG_BLOCK, &sigset, NULL);

	printf("My PId %d\n", getpid());

	while(1){
		printf("%d\n", i);
		i++;
		sleep(1);

		if(sigpending(&pendingset) == 0){

				if(sigismember(&pendingset, SIGUSR1)){
					printf("Block signal : SIGUSR1\n");
					break;
				}

		}

	}

}
