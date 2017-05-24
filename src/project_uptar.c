#include "project.h"

#include "utils/file.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

BOOL project_uptar(cmplx const * const c, char const * const path)
{
	uint read = 0;
	uint new_lines = 0;
	char buf[1];
	char *cfg_path;
	FILE *f;

	cfg_path = path_combine(path, CFG_NAME);

	f = fopen(cfg_path, "r+");
	free(cfg_path);
	if (!f)
	{
		fprintf(stderr, "unable to open %s\n", cfg_path);
		return FALSE;
	}

	//move seek
	while (new_lines < 3)
	{
		read += fread(buf, sizeof(char), 1, f);
		if (buf[0] == '\n')
		{
			new_lines++;
		}
	}

	ftruncate(f, read);

	sprintf(f, "tar_r=");
	dec_sprint(f, &c->r);
	sprintf(f, "\ntar_i=");
	dec_sprint(f, &c->i);

	fclose(f);
	return TRUE;
}