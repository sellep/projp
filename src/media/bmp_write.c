#include "media.h"

#include <stdlib.h>
#include <stdio.h>

#define BMP_HEAD_SIZE 54
#define BMP_FILE_HEADER_SIZE 14
#define BMP_INFO_HEADER_SIZE 40

BOOL bmp_write(uint const width, uint const height, color const * const pixels, char const * const fname)
{
	uint ix;
	uint iy;
	uint x;
	uint y;
	byte *img;
	uint bmp_body_size;
	uint filesize;
	byte bmp_file_header[BMP_FILE_HEADER_SIZE] = { 'B','M', 0, 0,0, 0, 0, 0, 0, 0, 54, 0, 0, 0 };
	byte bmp_info_header[BMP_INFO_HEADER_SIZE] = { 40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0 };
	byte bmp_pad[3] = { 0, 0, 0 };
	FILE *f;

	bmp_body_size = 3 * width * height;
	filesize = bmp_body_size + BMP_FILE_HEADER_SIZE + BMP_INFO_HEADER_SIZE;

	img = (byte*) malloc(bmp_body_size);

	for (ix = 0; ix < width; ix++)
	{
		for (iy = 0; iy < height; iy++)
		{
			x = ix;
			y = (height - 1) - iy;

			img[(x + y*width) * 3 + 2] = pixels[iy * width + ix].r;
			img[(x + y*width) * 3 + 1] = pixels[iy * width + ix].g;
			img[(x + y*width) * 3 + 0] = pixels[iy * width + ix].b;
		}
	}

	bmp_file_header[2] = (byte)filesize;
	bmp_file_header[3] = (byte)(filesize >> 8);
	bmp_file_header[4] = (byte)(filesize >> 16);
	bmp_file_header[5] = (byte)(filesize >> 24);

	bmp_info_header[4] = (byte)width;
	bmp_info_header[5] = (byte)(width >> 8);
	bmp_info_header[6] = (byte)(width >> 16);
	bmp_info_header[7] = (byte)(width >> 24);
	bmp_info_header[8] = (byte)height;
	bmp_info_header[9] = (byte)(height >> 8);
	bmp_info_header[10] = (byte)(height >> 16);
	bmp_info_header[11] = (byte)(height >> 24);

	//file writing, maybe should be removed and just pointer to raw bmp should returned
	f = fopen(fname, "wb");
	if (!f)
	{
		free(img);
		return FALSE;
	}

	fwrite(bmp_file_header, 1, BMP_FILE_HEADER_SIZE, f);
	fwrite(bmp_info_header, 1, BMP_INFO_HEADER_SIZE, f);

	for (iy = 0; iy < height; iy++)
	{
		fwrite(img + (width * (height - iy - 1) * 3), 3, width, f);
		fwrite(bmp_pad, 1, (4 - (width * 3) % 4) % 4, f);
	}

	fclose(f);
	free(img);
	return TRUE;
}
