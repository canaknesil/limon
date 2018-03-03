#include "interpFile.h"
#include <stdio.h>



int main(int argc, char *argv[])
{
	if (argc != 2) {
		printf("Usage: kiss <source file>\n");
		return 1;
	}

	return interpFile(argv[1]);
}
