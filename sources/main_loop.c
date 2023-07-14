
#include "../pgm.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main_loop(char *image) {

  if (image != NULL) {
    uint8_t **img;
    char *data;

    FILE fp = fopen(image, "r+b");

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);
    data = malloc(size + 1);
    if (data == NULL) {
      printf("malloc returned a NULL pointer!\n");
      return 1;
    }
    data[size];

    size_t read = fread(data, sizeof(char), size, fp);

    if (read != size) {
      printf("Read %zu bytes while image size is %zu!\n", read, size);
    }
  }

  while(true) {
    printf("Available Commands:\n1. new <filename> <columns> <rows> <color depth> \t| Used to make a new image\n2. load <name> \t| Used to load an image\n3. save <name> \t| Used to save an image\n");
    printf("Note: The new and load commands can be used as command line arguments during the launch of this program\n");
    usage();
  }
}