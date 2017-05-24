#include "media.h"

#include <stdlib.h>

void palette_free(palette * plt)
{
	free(plt->clr);
	free(plt);
}