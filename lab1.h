#pragma once

void select(int* mass, const size_t size, const enum ESort eSort);
void print(const int* mass, const size_t size, const unsigned column);
float get_median(const int* mass, const size_t size);
void print_moda(const int* mass, const size_t size);
float get_average(const int* mass, const size_t size);
int get_max(const int* mass, const size_t size);
int get_min(const int* mass, const size_t size);
int get_range(const int* mass, const size_t size);
float get_dispersion(const int* mass, const size_t size);
float get_st_deviation(const int* mass, const size_t size);
void hist(const int*mass, const size_t size, int* count, const size_t bins);
void print_hist(const int* mass, const size_t size, const int* count, const size_t bins);
