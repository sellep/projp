#include "project.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	project proj;
	project_read(&proj, "/home/pascal/Documents/def.proj");

	printf("width: %zu\n", proj.width);
	printf("height: %zu\n", proj.height);

	return 0;
}
