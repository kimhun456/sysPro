

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/types.h>


// 마지막에 널값을 넣어준다.
#define chop(str) str[strlen(str)-1] = 0x00;


int main(int argc, char ** argv){
	
	char buf[256];

	printf("My Shell\n");

	int pid;
	while(1){
		
		printf("# ");

		fgets(buf, 255, stdin);

		chop(buf);
		
		if(strncmp(buf, "quit", 4) == 0){
			exit(0);
		}

		/**
		입력한 명령이 실행가능한 프로그램이라면
		fork한 후 execl을 이용해서 실행한다.
		  */

		if(access(buf, X_OK) == 0){
			pid = fork();

			if(pid<0){
				exit(0);
				fprintf(stderr,"ForkError");
			}

			if(pid == 0){
				if(execl(buf,buf,NULL) == -1){
					fprintf(stderr, "Command Exec Error \n\n");
					exit(0);
				}
				
			}
			else{
				
				int status;
				waitpid(pid,&status, WUNTRACED);


			}

		}else{

			fprintf(stderr, "Command Not Found\n\n");

		}


	}


}
