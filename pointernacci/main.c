#include <stdio.h>
#include <stdlib.h>

#include "root.h"

#define ADD 'a'
#define CREATE 'c'
#define DUMP 'd'
#define EXTEND 'e'
#define INDEX 'i'
#define PRINT 'p'
#define QUIT 'q'
#define SIZE 's'
#define NO_ACTION '\0'

#define RETURN_PREFIX "\t-> "


bool is_valid_option(char option) {
	bool is_valid = false;

	is_valid = option == ADD
		|| option == CREATE
		|| option == DUMP
		|| option == EXTEND
		|| option == INDEX
		|| option == PRINT
		|| option == QUIT
		|| option == SIZE;

	return is_valid;
}


char print_menu(void) {
	char option;

	printf(
		"\nWelcome to Pointernacci experience, these are the available options:\n"
		"\n"
		"\t*****************************************************************\n"
		"\t* (a): Add the next element in the succession                   *\n"
		"\t* (c): Create a new succession                                  *\n"
		"\t* (d): Dump the sucession to a file                             *\n"
		"\t* (e): Extend the sucession                                     *\n"
		"\t* (i): Retrieve the nth-elemnt                                  *\n"
		"\t* (p): Print the sucession                                      *\n"
		"\t* (s): Calculate the size of the succession                     *\n"
		"\t* (q): Quit                                                     *\n"
		"\t*****************************************************************\n"
		"\nPlease enter your choice: ");

	fscanf(stdin, "%c", &option);

	return option;
}

int main(void) {
	char option = NO_ACTION;
	root r = root_create();

	do {
		option = print_menu();

		if (is_valid_option(option)) {
			switch (option) {
				case ADD:
					break;
				case CREATE:
					break;
				case DUMP:
					break;
				case EXTEND:
					break;
				case INDEX:
					break;
				case PRINT:
					break;
				case SIZE:
					break;
				case QUIT:
					root_destroy(r);
					printf(RETURN_PREFIX "Exiting.\n");
					return EXIT_SUCCESS;
				default:
					printf("\n\"%c\" is not a valid option, please try again.\n\n", option);
					break;
			}
		}
	} while (option != QUIT);
	return EXIT_SUCCESS;
}
