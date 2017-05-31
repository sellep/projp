#include "fractal.h"

#include <stdlib.h>

iframe_init(iframe * const f, project const * const p)
{
	f->width = p->width;
	f->height = p->height;
	f->iterations = p->iterations;
	f->frame = (uint*) malloc(sizeof(uint) * f->width * f->height);	
}
