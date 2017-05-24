#include "file.h"

#include <stdlib.h>
#include <string.h>

char* path_combine(char const * const path, char const * const name)
{
	char *full_path;
	uint len_path;
	uint len_name;

	len_path = strlen(path);
	len_name = strlen(name);

	full_path = (char*) malloc(sizeof(char) * (len_path + len_name + 2));

	memcpy(full_path, path, sizeof(char) * len_path);

	if (path[len_path - 1] == '/')
	{
		memcpy(full_path + len_path, name, sizeof(char) * len_name);
		full_path[len_path + len_name] = NULL_TERM;
	}
	else
	{
		full_path[len_path] = '/';
		memcpy(full_path + len_path + 1, name, sizeof(char) * len_name);
		full_path[len_path + 1 + len_name] = NULL_TERM;
	}

	return full_path;
}