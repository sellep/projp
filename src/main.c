#include "project.h"
#include "windows/windows.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	project proj;
	project_read(&proj, "/home/pascal/Documents/def.proj");

	printf("width: %zu\n", proj.width);
	printf("height: %zu\n", proj.height);
	printf("iterations: %zu\n", proj.iterations);
	printf("init_r_min: %f\n", proj.init_r_min);
	printf("init_r_max: %f\n", proj.init_r_max);
	printf("init_i_min: %f\n", proj.init_i_min);
	printf("init_i_max: %f\n", proj.init_i_max);
	printf("debug_plt_path: %s\n", proj.debug_plt_path);
	printf("allow_debug_host: %c\n", proj.allow_debug_host);

	project_free(&proj);

	int status = show_debug("/home/pascal/earth.jpg");
	printf("status: %i\n", status);
	return 0;
}
