#include "media.h"

#include <stdlib.h>

void palette_free(palette * const plt)
{
	free(plt->clr);
}
