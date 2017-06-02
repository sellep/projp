#include "project.h"

BOOL project_read_args(project * const proj, int const argc, char const * const * const argv)
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