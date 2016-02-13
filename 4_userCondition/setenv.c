

#include <stdio.h>
#include <unistd.h>


int main(){

	setenv("TEST", "YUNDREAM", 1);
	execl("/bin/bash","bash", NULL);


}
