#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "root.h"

struct s_root {
unsigned int size;
	struct s_node *first;
	struct s_node *second_to_last;
	struct s_node *last;
};

struct s_node {
	root_elem elem;
	struct s_node *next;
};

bool invrep(root r) {
	return r != NULL;
}

static struct s_node *
create_node(root_elem e) {
	struct s_node *node = (struct s_node *) malloc(sizeof (struct s_node));
	node->elem = e;
	node->next = NULL;
	return node;
}

static struct s_node *
destroy_node(struct s_node * node) {
	node->next = NULL;
	free(node);
	node = NULL;
	return node;
}

root root_create(void) {
	root new_root = NULL;
	struct s_node *first = NULL, *second = NULL;

	second = create_node(1);
	first = create_node(0);
	first->next = second;

	new_root = (root) malloc(sizeof (struct s_root));
	new_root->size = 2;
	new_root->first = first;
	new_root->second_to_last = first;
	new_root->last = second;

	assert(invrep(new_root) && !root_is_empty(new_root));
	return new_root;
}

root root_add_succesor(root r) {
	assert(invrep(r));
	struct s_node *succesor = NULL;

	succesor = (struct s_node *) malloc(sizeof (struct s_node));
	succesor->elem = r->second_to_last->elem + r->last->elem;
	succesor->next = NULL;

	r->second_to_last = r->last;
	r->last = succesor;
	r->second_to_last->next = r->last;
	r->size++;

	assert(invrep(r) && !root_is_empty(r));
	return r;
}

root root_extend(root r, unsigned int l) {
	assert(invrep(r));
	unsigned int succesors_added = 0u;

	while (succesors_added < l) {
		r = root_add_succesor(r);
		succesors_added++;
	}

	assert(invrep(r) && !root_is_empty(r));
	return r;
}

bool root_is_empty(root r) {
	assert(invrep(r));	
	return r->size == 0u;
}

unsigned int root_size(root r) {
	assert(invrep(r));
	return r->size;
}

root_elem root_index(root r, unsigned int i) {
	assert(invrep(r) && i < root_size(r));
	unsigned int current = 0u;
	struct s_node *p = r->first;
	root_elem e;

	while (current < i) {
		p = p->next;
		current++;
	}

	e = p->elem;

	assert(invrep(r));
	return e;
}

void root_dump(root r, FILE * file) {
	assert(invrep(r));
	struct s_node *p = r->first;

	while (p != NULL) {
		fprintf(file, "%llu ", p->elem);
		p = p->next;
	}
}

root root_destroy(root r) {
	struct s_node *p = r->first;

	while (p != NULL) {
		struct s_node *destroyed = p;
		p = p->next;
		destroyed = destroy_node(destroyed);
	}

	free(r);
	r = NULL;
	assert(r == NULL);
	return r;
}
