#include <stdio.h>
#include <unistd.h>

int main(int argc, char **argv){

	printf("Start\n");

	execl("/bin/ls", "ls", "-al", NULL);

	printf("End\n");


}
