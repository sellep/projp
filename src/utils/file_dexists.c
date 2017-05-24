#include "file.h"

#include <dirent.h>

BOOL dexists(char const * const path)
{
	DIR *dir = opendir(path);
	if (!dir)
		return FALSE;

	closedir(dir);
	return TRUE;
}