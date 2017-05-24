#ifndef __P_MEDIA_H
#define __P_MEDIA_H

#include "../defs.h"

typedef struct
{
	byte r;
	byte g;
	byte b;
} color;

typedef struct
{
	color *clr;
	uint len;
} palette;

palette* palette_init(uint const);
void palette_free(palette*);
void palette_ipol(palette const * const, color const * const, uint const);
BOOL palette_write(palette const, char const * const);
BOOL palette_read(palette * const, char const * const);

#endif