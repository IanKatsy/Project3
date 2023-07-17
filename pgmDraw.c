/*
    *   IOANNIS KATSIYIANNIS
    *   AM: 2022202200081
    *   Email:  dit22081@go.uop.gr
    *
    *   SOTIRIOS-ELEFTHERIOS DIMITROUSIS
    *   AM: 2022202100048
    *   Email: dit21048@go.uop.gr
*/

#include "pgm.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

enum argv_names {
	arg_program = 0,
	arg_flag,
	arg_name,
	arg_columns,
	arg_rows,
	arg_depth
};

int main(int argc, char **argv) {

	char *file = NULL;

	switch (argc) {

		case 3:

			if (strcmp(argv[arg_flag], "-l") != 0) {
				file = NULL;
				break;
			}

			size_t len = strlen(argv[arg_name]) + strlen(".pgm");
			file = malloc(len + 1);
			file[len] = 0;

			strcpy(file, argv[arg_name]);
			strcat(file, ".pgm");

			if (access(file, F_OK)) {
				printf("File %s does not exist!\n", file);
				file = NULL;
				break;
			}

			break;
		case 6:

			if (strcmp(argv[arg_flag], "-n") != 0) {
				file = NULL;
				break;
			}

			break;

		default:
			break;
	}

	return main_loop(file);
}