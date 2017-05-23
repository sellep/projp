#ifndef __P_MEDIA_H
#define __P_MEDIA_H

#include "../defs.h"

typedef struct
{
	ubyte r;
	ubyte g;
	ubyte b;
} color;

typedef struct
{
	color *plt;
	uint len;
} palette;

void palette_ipol(palette * const, color * const * const, uint const);
BOOL palette_write(palette const, char const * const);
BOOL palette_read(palette * const, char const * const);

#endif