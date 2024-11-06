#include <stdio.h>
#include <stdlib.h>
#include "lab1.h"
#include <time.h>

enum ESort {
	UP = 0,
	DOWN
};

#define ARRAY_SIZE 100 

void generate_random(int* array, int size, int a, int b) {
    for (int i = 0; i < size; i++) {
        array[i] = rand() % (b - a + 1) + a; // Генерируем число в интервале [a, b]
    }
}

int main() {
    int a, b;
    int mass[ARRAY_SIZE];


    srand(time(0));

    // Ввод значений a и b
    printf("Введите интервал [a, b]:\n");
    printf("a = ");
    a = -1000;
    scanf("%d ", &a);
    printf("b = \n");
    b = 1000;
    scanf("%d ", &b);

    // Проверка на корректность 
    if (a > b) {
        printf("Ошибка: убедиттесь что a меньше или равно b.\n");
        return 0;
    }

    // Генерация массива 
    generate_random(mass, ARRAY_SIZE, a, b);

    // Вывод массива на экран
    printf("Сгенерированный массив:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d ", mass[i]);
    }

    printf("\n");

    const size_t bins = 100;
    int count[bins] = { 0 };
    int st;

    select(mass, ARRAY_SIZE, UP);
    printf("Введите количество столбцов \n");
    scanf("%d ", &st);
    print(mass, ARRAY_SIZE, st);
    get_median(mass, ARRAY_SIZE);
    print_moda(mass, ARRAY_SIZE);
    float av = get_average(mass, ARRAY_SIZE);
    printf("average = %f \n", av);
    int maxi = get_max(mass, ARRAY_SIZE);
    printf("max = %d \n", maxi);
    int mini = get_min(mass, ARRAY_SIZE);
    printf("mini = %d \n", mini);
    int range = get_range(mass, ARRAY_SIZE);
    printf("range = %d \n", range);
    float dis = get_dispersion(mass, ARRAY_SIZE);
    printf("dispersion = %f \n", dis);
    float deviation = get_st_deviation(mass, ARRAY_SIZE);
    printf("deviation = %f \n", deviation);
    hist(mass, ARRAY_SIZE, count, bins);
    print_hist(mass, ARRAY_SIZE, count, bins);
    return 0;
}
