#ifndef __P_UTILS_FILE_H
#define __P_UTILS_FILE_H

#include "../defs.h"

#define TERMINATING_NULL '\0'

enum file_errors
{
	OK = 0,
	FOPEN_FAILED = -1,
	FCLOSE_FAILED = -2,
};

int fwrite_all(void const * const, uint const, char const * const);
long fread_all(void * * const, char const * const);

#endif