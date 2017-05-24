#include "project.h"

#include "utils/file.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

BOOL project_create(project const * const p, char const * const path)
{
	int c;
	char *buf;
	FILE *f;

	if (dexists(path))
	{
		fptrint(stderr, "dir %s already exists\n", path);
		return FALSE;
	}

	if ((c = mkdir(path, 0777)) != 0)
	{
		fptrint(stderr, "mkdir %s failed: %i\n", path, c);
		return FALSE;
	}

	buf = path_combine(path, IFRAME_DIR_NAME);
	c = mkdir(buf, 0777);
	free(buf);

	if (c != 0)
	{
		fptrint(stderr, "mkdir %s failed: %i\n", path, c);
		return FALSE;
	}

	buf = path_combine(path, CFG_NAME);
	f = fopen(buf, "a+");

	sprintf(f, "width=%u", p->width);
	sprintf(f, "\nheight=%u", p->height);
	sprintf(f, "\niterations=%u", p->iterations);

	sprintf(f, "\ntar_r=");
	dec_sprint(f, &p->tar.r);
	sprintf(f, "\ntar_i=");
	dec_sprint(f, &p->tar.i);

	fclose(f);
	return TRUE;
}