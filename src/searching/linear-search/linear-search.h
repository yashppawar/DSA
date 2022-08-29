#ifndef _LINEAR_SEARCH_H_
#define _LINEAR_SEARCH_H_

#include <stdio.h>

#define TRUE  1
#define FALSE 0

#define DATA_NOT_FOUND -1

typedef int data_t;
typedef short Bool;

size_t lsearch(data_t data, data_t* p_arr, size_t size);
Bool find(data_t data, data_t* p_arr, size_t size);

#endif
