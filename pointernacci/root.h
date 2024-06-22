#ifndef ROOT_H
#define ROOT_H

#include <stdio.h>
#include <stdbool.h>

typedef struct s_root * root;

typedef unsigned long long int root_elem;

root root_create(void);
/**
 * DESC: Creates the needed structure for a "pointernacci" proccedure.
 *
 * Note: This will create a root with the two first elements in the fibonacci succession (0 and 1).
 *
 * PRE: {true}
 * 	r = root_create();
 * POS: {r --> root && !root_is_empty(r)}
 */

root root_add_succesor(root r);
/**
 * DESC: Adds the succesor of root [r] to the end of it.
 *
 * PRE: {r --> root}
 * 	r = root_add_succesor(r);
 * POS: {r --> root && !root_is_empty(r)}
 */

root root_extend(root n, unsigned int l);
/**
 * DESC: Adds [l] succesors to the [r] root.
 *
 * PRE: {r --> root}
 * 	r = root_extend(r, l);
 * POS: {r --> root && !root_is_empty(r)}
 */

bool root_is_empty(root r);
/**
 * DESC: Indicates if [r] root is empty or not.
 *
 * PRE: {r --> root}
 * 	b = root_is_empty(r);
 * POS: {r --> root}
 */

unsigned int root_size(root r);
/**
 * DESC: Returns the number of elements of the [r] root.
 *
 * PRE: {r --> root}
 * 	l = root_length(r);
 * POS: {r --> root}
 */ 

root_elem root_index(root r, unsigned int i);
/**
 * DESC: Returns the [i]-th element of the [r] root.
 *
 * PRE: {r --> root && i < root_size(r)}
 * 	e = root_index(n, i);
 * POS: {r --> root && e --> root_elem}
 */

void root_dump(root r, FILE * file);
/**
 * DESC: Dumps [r] root content into the file pointed by [file] 
 *
* PRE: {r --> root && file --> FILE}
 * 	root_dump(r, file);
 */

root root_destroy(root r);
/**
 * DESC: Destroys the [r] root.
 *
 * PRE: {r --> root}
 * 	r = root_destroy(n);
 * POS: {r == NULL}
 */

#endif
