#include "file.h"

#include <stdlib.h>
#include <string.h>

char* path_combine(char const * const path, char const * const name)
{
	char *full_path;
	uint len_path;
	uint len_name;
	uint off_slash = 0;

	len_path = strlen(path);
	len_name = strlen(name);

	full_path = (char*) malloc(sizeof(char) * (len_path + len_name + 2));

	memcpy(full_path, path, sizeof(char) * len_path);

	if (path[len_path - 1] != '/')
	{
		full_path[len_path] = '/';
		off_slash = 1;
	}

	memcpy(full_path + len_path + off_slash, name, sizeof(char) * len_name);
	full_path[len_path + off_slash + len_name] = NULL_TERM;

	return full_path;
}