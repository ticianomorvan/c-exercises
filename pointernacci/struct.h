#ifndef STRUCT_H
#define STRUCT_H

#include <stdio.h>
#include <stdbool.h>

typedef struct s_node * node;

typedef unsigned long long int node_elem;

node node_create(void);
/**
 * DESC: Creates the needed structure for a "pointernacci" proccedure.
 *
 * Note: This will create a node with the two first elements in the fibonacci succession (0 and 1).
 *
 * PRE: {true}
 * 	n = node_create();
 * POS: {n --> node && !node_is_empty(n)}
 */

node node_add_succesor(node n);
/**
 * DESC: Adds the succesor of node [n] to the end of it.
 *
 * PRE: {n --> node}
 * 	n = node_add_succesor(n);
 * POS: {n --> node && !node_is_empty(n)}
 */

node node_extend(node n, unsigned int l);
/**
 * DESC: Adds [l] succesors to the [n] succession.
 *
 * PRE: {n --> node}
 * 	n = node_extend(n, l);
 * POS: {n --> node && !node_is_empty(n)}
 */

bool node_is_empty(node n);
/**
 * DESC: Indicates if [n] is empty or not.
 *
 * PRE: {n --> node}
 * 	b = node_is_empty(n);
 * POS: {n --> node}
 */

unsigned int node_length(node n);
/**
 * DESC: Returns the number of elements of the [n] succession.
 *
 * PRE: {n --> node}
 * 	l = node_length(n);
 * POS: {n --> node}
 */ 

node_elem node_index(node n, unsigned int i);
/**
 * DESC: Returns the [i]-th element of the [n] succession.
 *
 * PRE: {n --> node && index < node_length(n)}
 * 	e = node_index(n, i);
 * POS: {n --> node && e --> node_elem}
 */

void node_dump(node n, FILE * file);
/**
 * DESC: Dumps node [n] content into the file pointed by [file] 
 *
* PRE: {n --> node && file --> FILE}
 * 	node_dump(n, file);
 */

node node_destroy(node n);
/**
 * DESC: Destroys the node [n].
 *
 * PRE: {n --> node}
 * 	n = node_destroy(n);
 * POS: {n == NULL}
 */

#endif
