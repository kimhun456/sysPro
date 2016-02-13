

#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int main(int argc, char **argv){




	int pid;
	int sig_num;


	if(argc !=3){

		return 1;

	}


	pid  = atoi(argv[1]);
	sig_num = atoi(argv[2]);

	if(!kill(pid,sig_num)){

		perror("Signal Send Error");
		return 1;
	}

	return 0;

}
