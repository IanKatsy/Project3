#ifndef PROJECT3_PGM_H
#define PROJECT3_PGM_H


#define ALLOC_ERROR perror("Memory allocation failed!\n");

struct image_struct {
	char *code,
			*comment,
			*columns_rows,
			*depth;
	unsigned char **pixel_map;
};

typedef struct image_struct Image;

int main_loop(char *image);

Image *gen_img(const char *comment, int columns, int rows, int depth);

void save_img(Image *img, char *filename);

#endif //PROJECT3_PGM_H
