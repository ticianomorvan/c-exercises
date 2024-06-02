#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define ARRAY_SIZE 6

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

float select_best_coin(float rest, float coins[], float coins_length) {
	float best_coin = 0.0;
	float smallest_rest = UINT_MAX;

	for (int i = 0; i < coins_length; ++i) {
		if (coins[i] <= rest) {
			float rest_without_coin = rest / coins[i];

			if (rest_without_coin <= smallest_rest) {
				best_coin = coins[i];
				smallest_rest = rest_without_coin;
			}
		}
	}

	return best_coin;	
}

float *calculate_coins_needed(float total, float coins[], float coins_length) {
  float *used_coins = NULL;
	float rest = total;
	float current_coin = 0.0;
	int j = 0;

	used_coins = (float*) calloc(coins_length, sizeof (float));

	while (rest != 0.0) {
		current_coin = select_best_coin(rest, coins, coins_length);

		if (current_coin <= rest) {
			while (rest >= current_coin) {
				rest = rest - current_coin;
			}
	
			used_coins[j] = current_coin;
			++j;
		}
	}

	return used_coins;
}

int main(void) {
	float coins[] = { 0.10, 0.25, 0.50, 1.0 };
	int coins_length = (float) sizeof (coins) / sizeof (float);	

	float total = 50.25;
	float *solution = calculate_coins_needed(total, coins, coins_length);

	printf("Para un total de %.2f, se pueden usar monedas de: ", total);
	print_array(solution, (float) sizeof (solution) / sizeof (float));

	free(solution);
	return 0;
}
