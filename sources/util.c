
#include "../pgm.h"

#include <stdio.h>

void usage(void) {
  printf("Usage: %s -l <name>                                \t| Used to load an image\n", argv[0]);
  printf("       %s -n <name> <columns> <rows> <color depth> \t| Used to make a new image\n", argv[0]);
}
