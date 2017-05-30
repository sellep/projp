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
	size_t len;
} palette;

void color_rand(color * const);

palette* palette_init(uint const);
void palette_free(palette * const);
void palette_ipol(palette const * const, color const * const, size_t const);
BOOL palette_write(palette const * const, char const * const);
BOOL palette_read(palette * const, char const * const);

BOOL bmp_write(uint const, uint const, color const * const, char const * const);

#endif
