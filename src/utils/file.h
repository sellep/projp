#ifndef __P_UTILS_FILE_H
#define __P_UTILS_FILE_H

#include "../defs.h"

#define NULL_TERM '\0'

enum file_errors
{
	FOK = 0,
	FOPEN_FAILED = -1,
	FCLOSE_FAILED = -2,
};

BOOL fexists(char const * const);
BOOL dexists(char const * const);
int fwrite_all(void const * const, uint const, char const * const);
long fread_all(void * * const, char const * const);
BOOL fnext(char * * const, char const * const);

char* path_combine(char const * const, char const * const);
BOOL path_dir(char * * const, char const * const);

#endif
