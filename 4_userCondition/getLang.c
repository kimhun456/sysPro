#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{

	char *value = NULL;

	value = getenv("LANG");

	printf("LANG is %s\n", value);
	return 0;

}
