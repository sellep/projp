#include "media.h"

#include <stdlib.h>

palette* palette_init(uint const len)
{
	palette *p = (palette*) malloc(sizeof(color*) + sizeof(uint) + len * sizeof(color));

	p->len = len;
	p->clr = (color*)(p + 1);

	return p;
}