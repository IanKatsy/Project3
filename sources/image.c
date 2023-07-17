#include "../pgm.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Image *gen_img(const char *comment, int columns, int rows, int depth) {
	Image *img = malloc(sizeof(Image));
	if (img == NULL) {
		ALLOC_ERROR
		exit(EXIT_FAILURE);
	}

	char buff1[1024] = {0}; // overkill idc
	char buff2[512] = {0};

	sprintf(buff1, "%d %d\n", columns, rows);
	sprintf(buff2, "%d\n", depth);

	img->code = "P5\n";
	img->comment = strdup(comment);
	img->columns_rows = strdup(buff1);
	img->depth = strdup(buff2);

	img->pixel_map = malloc(sizeof(unsigned char *) * rows);
	if (img->pixel_map == NULL) {
		ALLOC_ERROR
		exit(EXIT_FAILURE);
	}

	printf("pixel_map addr = %p\n", img->pixel_map);

	int i;
	for (i = 0; i < rows; i++) {

		img->pixel_map[i] = malloc(sizeof(unsigned char) * columns);
		if (img->pixel_map[i] == NULL) {
			ALLOC_ERROR
			exit(EXIT_FAILURE);
		}
	}

	size_t a = rows * columns;

	memset(img->pixel_map, 0, a);

	int j, k;

	for (i = 0; i < a; i++) {
		*(((unsigned char *) img->pixel_map) + i) = (unsigned char) i;
	}

	return img;
}

void save_img(Image *img, char *filename) {

	FILE *fp = fopen(filename, "wb");

	fwrite(img->code, sizeof(char), strlen(img->code), fp);
	fwrite(img->comment, sizeof(char), strlen(img->comment), fp);
	fwrite(img->columns_rows, sizeof(char), strlen(img->columns_rows), fp);
	fwrite(img->depth, sizeof(char), strlen(img->depth), fp);
	fwrite(img->pixel_map, sizeof(char), 256 * 256, fp);

	fclose(fp);
}