#include <stdio.h>
#include "lab1.h"
#include "math.h"


void select(int* mass, const size_t size, const enum ESort eSort) {
	if (size == 0) {
		return;
	}
	int t;
	switch (eSort) {
	case 0:
		for (size_t s = 0; s < size; s++) {
			for (size_t i = s + 1; i < size; i++) {
				if (mass[s] > mass[i]) {
					t = mass[s];
					mass[s] = mass[i];
					mass[i] = t;
				}
			}
		}
		break;
	case 1:
		for (size_t s = 0; s < size; s++) {
			for (size_t i = s + 1; i < size; i++) {
				if (mass[s] < mass[i]) {
					t = mass[s];
					mass[s] = mass[i];
					mass[i] = t;
				}
			}
		}
		break;
	}
}

void print(const int* mass, const size_t size, const unsigned column) {
	if (size == 0 || column == 0) {
		return;
	}
	for (size_t i = 0; i < size; i++) {
		for (unsigned s = 1; s < column; s++) {
			if (mass[i] > 0) {
				printf("+%d ", mass[i]);
				if (i == size-1) {
					break;
				}
				i++;
			}
			else {
				printf("%d ", mass[i]);
				if (i == size-1) {
					break;
				}
				i++;
			}
		}
		if (mass[i] > 0) {
			printf("+%d \n", mass[i]);
		}
		else {
			printf("%d \n", mass[i]);
		}
	}
}

float get_median(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	} 
	select(mass, size,0);
	if (size % 2 == 1) {
		printf("med = %d \n", mass[size / 2]);
	}
	else {
		printf("med = %d \n", (mass[size / 2] + mass[size / 2 - 1]) / 2);
	}
}

void print_moda(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	}
	select(mass, size,0);
	int k = 1;
	int s = 1;
	int maxi = 0;
	int z = 0;
	for (size_t i = 0; i < size-1; i++) {
		if (mass[i] == mass[i + 1]) {
			k++;
			if (maxi < k) {
				maxi = k;
			}
		}
		else {
			k = 1;
		}
	}
	for (size_t i = 0; i < size - 1; i++) {
		if (mass[i] == mass[i + 1]) {
			s++;
		}
		if (mass[i] != mass[i + 1] && s == maxi) {
			printf("mod = %d \n", mass[i]);
			s = 1;
		}
	}
}

float get_average(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	} 
	float summ = 0;
	for (size_t i = 0; i < size; i++) {
		summ = summ + mass[i];
	}
	return (summ/size);
}

int get_max(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	} 
	select(mass, size,0);
	return mass[size-1];
}

int get_min(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	}
	select(mass, size,0);
	return mass[0];
}

int get_range(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	} 
	select(mass, size, 0);
	return (mass[size-1] - mass[0]);
}

float get_dispersion(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	} 
	float sr = get_average(mass, size);
	float su = 0;
	for (size_t i = 0; i < size; i++) {
		su = su + (mass[i] - sr) * (mass[i] - sr);
	}
	return (su / (size-1));
}

float get_st_deviation(const int* mass, const size_t size) {
	if (size == 0) {
		return;
	}  
	float sq = get_dispersion(mass, size);
	return (sqrtf(sq));
}

void hist(const int* mass, const size_t size, int* count, const size_t bins) {
	if (size == 0 || bins == 0) {
		return;
	}
	int mini = get_min(mass, size);
	int maxi = get_max(mass, size);

	float width = (float)(maxi - mini) / bins;

	for (size_t i = 0; i < size; i++) {
		int ind = (mass[i] - mini)/width;
		if (ind >= bins) {
			ind = bins - 1;
		}
		count[ind]++;
	}
}

void print_hist(const int* mass, const size_t size, const int* count, const size_t
	bins) {
	if (size == 0 || bins == 0) {
		return; 
	}
	int mini = get_min(mass, size);
	int maxi = get_max(mass, size);

	float width = (float)(maxi - mini) / bins;

	for (size_t i = 0; i < bins; i++) {
		float lower = mini + i * width;
		float upper = lower + width;
		printf("[%.2f, %.2f]: ", lower, upper);

		for (int j = 0; j < count[i]; j++) {
			printf("■");
		}
		printf("\n");
	}
}

