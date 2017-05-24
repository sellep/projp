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

	sprintf(f, "width=%u\n", p->width);
	sprintf(f, "height=%u\n", p->height);
	sprintf(f, "iterations=%u\n", p->iterations);

	//tar_r
	//tar_i

	fclose(f);
	return TRUE;
}