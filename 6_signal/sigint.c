#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void sig_handler(int signo);

int main(int argc, char **argv){

	int i = 0;
	signal(SIGINT, SIG_IGN);

	while(1){

		printf("%d\n",i);
		sleep(2);
		i++;

	}



	return 0;
}

void sig_handler(int signo){

	printf("I received SIGINT(%d) \n", SIGINT);
	sleep(4);
}
