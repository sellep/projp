#include "project.h"

#include "utils/file.h"

#include <stdlib.h>
#include <stdio.h>

BOOL project_read(project * const p, char const * const path)
{
	char *cfg_path;
	FILE *f;

	cfg_path = path_combine(path, CFG_NAME);

	f = fopen(cfg_path, "r");

	if (!f)
	{
		fptintf(stderr, "unable to open %s\n", cfg_path);
		free(cfg_path);
		return FALSE;
	}


	fclose(f);
	free(cfg_path);
	return TRUE;
}