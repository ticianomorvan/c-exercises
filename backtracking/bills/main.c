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

int change(int bills[], int index, int amount) {
	int result;

	if (amount == 0) {
		result = 0;
	} else if (index == -1) {
		result = INT_MAX;
	} else if (bills[index] > amount) {
		result = change(bills, index - 1, amount);
	} else {
		result = MIN(change(bills, index - 1, amount), 1 + change(bills, index, amount - bills[index]));
	}

	return result;
}

int main(void) {
	int amount;
	int bills[] = { 5, 10, 25 };
	int bills_length = (int) sizeof (bills) / sizeof (int);

	printf("Escribe un total a dar cambio en billetes de 5, 10 y 25: ");
	scanf("%i", &amount);

	int change_to_give = change(bills, bills_length - 1, amount);
	printf("El cambio se puede dar con %i billetes\n", change_to_give);

	return 0;
}
