#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "struct.h"

struct s_node {
	node_elem elem;
	struct s_node *next;
};

bool invrep(node n) {
	return n != NULL;
}

node node_create(void) {
	node first = NULL, second = NULL;

	second = (node) malloc(sizeof (struct s_node));
	second->elem = 1;
	second->next = NULL;

	first = (node) malloc(sizeof (struct s_node));
	first->elem = 0;
	first->next = second;

	assert(invrep(first) && !node_is_empty(first));
	return first;
}

node node_add_succesor(node n) {
	assert(invrep(n));
	node second_to_last = NULL, last = n, succesor = NULL;

	while (last->next != NULL) {
		second_to_last = last;
		last = last->next;
	}

	succesor = (node) malloc(sizeof (struct s_node));
	succesor->elem = second_to_last->elem + last->elem;
	succesor->next = NULL;
	last->next = succesor;

	assert(invrep(n) && !node_is_empty(n));
	return n;
}

node node_extend(node n, unsigned int l) {
	assert(invrep(n));
	unsigned int succesors_added = 0u;

	while (succesors_added <= l) {
		n = node_add_succesor(n);
		succesors_added++;
	}

	assert(invrep(n) && !node_is_empty(n));
	return n;
}

bool node_is_empty(node n) {
	assert(invrep(n));	
	return n == NULL;
}

unsigned int node_length(node n) {
	assert(invrep(n));
	unsigned int length = 0u;
	node p = n;

	while (p != NULL) {
		p = p->next;
		length++;
	}

	assert(invrep(n));
	return length;
}

node_elem node_index(node n, unsigned int i) {
	assert(invrep(n) && i < node_length(n));
	unsigned int current = 0u;
	node p = n;
	node_elem e;

	while (current < i) {
		p = p->next;
		current++;
	}

	e = p->elem;

	assert(invrep(n));
	return e;
}

void node_dump(node n, FILE * file) {
	assert(invrep(n));
	node p = n;

	while (p != NULL) {
		fprintf(file, "%llu ", p->elem);
		p = p->next;
	}
}

node node_destroy(node n) {
	node p = n->next, q = NULL;

	while (p != NULL) {
		q = p;
		p = p->next;

		q->next = NULL;
		free(q);
	}

	free(n);
	n = NULL;
	assert(n == NULL);
	return n;
}
