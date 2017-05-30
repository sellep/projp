#include "media.h"

#include <stdlib.h>

void color_rand(color * const c)
{
	c->r = (byte) rand() % 256;
	c->g = (byte) rand() % 256;
	c->b = (byte) rand() % 256;
}
