#ifndef _SELECTION_SORT_H_
#define _SELECTION_SORT_H_

#include <stdio.h>

typedef int data_t;

void ssort(data_t* p_arr, size_t size);

static size_t argMin(data_t* p_arr, size_t size);

#endif
