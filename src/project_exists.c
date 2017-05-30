#include "project.h"

#include "utils/file.h"

#include <stdlib.h>

BOOL project_exists(char const * const path)
{
	uint len;
	char *cfg_path;
	BOOL result;

	if (!dexists(path))
		return FALSE;

	cfg_path = path_combine(path, CFG_NAME);
	result = fexists(cfg_path);
	free(cfg_path);
	return result;
}
