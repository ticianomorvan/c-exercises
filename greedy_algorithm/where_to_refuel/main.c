#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "structs.h"

#define ARRAY_SIZE 5

void print_locations(location locations[], unsigned int locations_length) {
	unsigned int i = 0;
	
	while (locations[i].distance_to_next > 0 && i < locations_length) {
		printf("Se deberá cargar antes de la localidad que queda a %u kilómetros\n", locations[i].distance_to_next);	
		++i;
	}
}

location *calculate_refuel(location locations[], unsigned int locations_length, automobile a) {
	location l;
	location *locations_to_refuel = NULL;
	unsigned int j = 0;
	unsigned int fuel_left = 0u;

	locations_to_refuel = (location *) calloc(locations_length, sizeof (location));

	for (unsigned int i = 0; i < locations_length; ++i) {
		l = locations[i];

		if (fuel_left < l.distance_to_next) {
			fuel_left = a.autonomy;
			locations_to_refuel[j] = l;
			++j;
		}

		fuel_left = fuel_left - l.distance_to_next;
	}

	return locations_to_refuel;
}

/* @EXERCISE P3-1 (4) - AYEII FAMAF */
int main(void) {
	automobile a;
	location locations[ARRAY_SIZE];

	a.autonomy = 2000;
	locations[0].distance_to_next = 200;
	locations[1].distance_to_next = 1600;
	locations[2].distance_to_next = 500;
	locations[3].distance_to_next = 1000;
	locations[4].distance_to_next = 800;

	location *locations_to_refuel = calculate_refuel(locations, ARRAY_SIZE, a);

	print_locations(locations_to_refuel, ARRAY_SIZE);

	free(locations_to_refuel);
	return 0;
}
