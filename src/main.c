#include "defs.h"
#include "project.h"
#include "windows/windows.h"

#include <stdio.h>
#include <stdlib.h>

BOOL open_project(int argc, char *argv[], project * const proj)
{
	if (argc != 2)
	{
		fprintf(stderr, "missing project file path!\n");
		return FALSE;
	}

	if (!project_read(proj, argv[1]))
	{
		fprintf(stderr, "failed to load project\n");
		return FALSE;
	}

	return TRUE;
}

int main(int argc, char *argv[])
{
	project proj;
	
	if (!open_project(argc, argv, &proj))
		return 1;

	

	int status = show_debug("/home/pascal/earth.jpg");


	project_free(&proj);
	return 0;
}
