#include "project.h"

#include <stdio.h>

int main(int argc, char *argv[])
{
	project proj;
	project_read(&proj, "/home/pascal/Documents/def.proj");

	printf("width: %zu\n", proj.width);
	printf("height: %zu\n", proj.height);
	printf("iterations: %zu\n", proj.iterations);
	printf("init_r_min: %f\n", proj.init_r_min);
	printf("init_r_max: %f\n", proj.init_r_max);

	return 0;
}
