#ifndef _BINARY_SEARCH_H_
#define _BINARY_SEARCH_H_

#include <stdio.h>

#define DATA_NOT_FOUND   -1
#define ARRAY_NOT_SORTED -2

#define TRUE  1
#define FALSE 0

typedef int data_t;
typedef short Bool;

size_t bsearch(data_t data, data_t* p_arr, size_t size);
Bool find(data_t data, data_t* p_arr, size_t size);
size_t binary_search(data_t data, data_t* p_arr, size_t start, size_t end);
static Bool isSorted(data_t* p_arr, size_t size);

#endif
