#include "file.h"

#include <stdlib.h>
#include <string.h>

BOOL path_dir(char * * const dir, char const * const path)
{
	ssize_t len;
	ssize_t off;
	int i;

	len = strlen(path);

	if (path[len - 1] == '/')
	{
		off = 2;
	}
	else
	{
		off = 1;
	}

	for (i = len - off; i >= 0; i--)
	{
		if (path[i] == '/')
			break;
	}

	if (i == -1)
		return FALSE;

	i++;

	dir[0] = (char*) malloc(sizeof(char) * (i + 1));

	memcpy(dir[0], path, sizeof(char) * i);
	dir[0][i + 1] = NULL_TERM;

	return TRUE;
}
