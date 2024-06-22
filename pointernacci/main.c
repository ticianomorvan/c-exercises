#include <stdio.h>
#include <stdlib.h>

#include "struct.h"

#define INDEX 500

int main(void) {
	node n = node_create();
	n = node_extend(n, INDEX);
	node_elem e = node_index(n, INDEX);
	printf("The %i-th element of the Fibonacci succession is: %llu\n", INDEX, e);
	node_dump(n, stdout);

	node_destroy(n);
	return EXIT_SUCCESS;
}
