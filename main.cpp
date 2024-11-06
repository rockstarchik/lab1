#include <stdio.h>
#include "lab1.h"

enum ESort {
	UP = 0,
	DOWN
};

int main() {
	int mass[10] = {2, 4, -5, 4, 12, 42, -7, 12, 6, 8 };
	int mass2[15] = { 3, 5,89,13,-36,5,-14,8, 99,-56,11,-1,0,-62,52 };
	const size_t bins = 5;
	int count[5] = {0};
	hist(mass, 10, count, bins);
	print(count,5,5);
	return 0;
}