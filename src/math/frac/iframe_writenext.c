#include "fractal.h"

#include "../../utils/file.h"

#include <stdlib.h>
#include <string.h>

BOOL iframe_writenext(iframe const * const req, char const * const fname)
{
	return TRUE;
	/*uint *buf;
	uint len;
	char *next;
	int res;

	len = sizeof(uint) * (req->width * req->height + 3);
	buf = (uint*) malloc(len);

	buf[0] = reg->width;
	buf[1] = reg->height;
	buf[2] = reg->iterations;

	memcpy(buf + 3, req->frame, sizeof(uint) * req->width * req->height);

	res = fnext(&next, fname);
	if (!res)
	{
		free(next);
		free(buf);
		return FALSE;
	}

	res = fwrite_all(buf, len, next);

	free(next);
	free(buf);

	if (res != FOK)
		return FALSE;

	return TRUE;*/
}
