#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#include <stdio.h>

#define TRUE 1

typedef int data_t;

void msort(data_t* p_arr, size_t size);

static void mergeSort(data_t* p_arr, size_t p, size_t q);
static void merge(data_t* p_arr, size_t start, size_t mid, size_t end);

#endif
