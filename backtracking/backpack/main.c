#include <stdio.h>
#include <stdlib.h>
#include <sys/param.h>
#include <limits.h>

void print_array(float array[], float length) {
	for (int i = 0; i < length; ++i) {
		printf("%.2f ", array[i]);	
	}

	printf("\n");
}

void copy_array(float array[], float new_array[], float length) {
	for (int i = 0; i < length; ++i) {
		new_array[i] = array[i];
	}
}

int backpack(int weights[], int index, int total_weight) {
	int result;

	if (total_weight == 0) {
		result = 0;
	} else if (index == -1) {
		result = 0;
	} else if (weights[index] > total_weight) {
		result = backpack(weights, index - 1, total_weight);
	} else {
		result = MAX(backpack(weights, index - 1, total_weight), 1 + backpack(weights, index, total_weight - weights[index]));
	}

	return result;
}

int main(void) {
	int total_weight;
	int weights[] = { 5, 6, 15, 20, 30 };
	int weights_length = (int) sizeof (weights) / sizeof (int);

	printf("Dé el peso total (en kilogramos) de la mochila: "); 
	scanf("%i", &total_weight);

	int items_to_carry = backpack(weights, weights_length - 1, total_weight);
	printf("Se pueden llevar %i elementos.\n", items_to_carry);

	return 0;
}
