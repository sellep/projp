#include "fractal.h"

#include <stdlib.h>

iframe_free(iframe * const f)
{
	free(f->frame);
}
