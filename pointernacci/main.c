#include <stdio.h>
#include <stdlib.h>

#include "root.h"

#define INDEX 0

int main(void) {
	root r = root_create();
	r = root_extend(r, 125);
	root_elem e = root_index(r, INDEX);
	printf("The %i-th element of the Fibonacci succession is: %llu\n", INDEX, e);
	root_dump(r, stdout);

	root_destroy(r);
	return EXIT_SUCCESS;
}
