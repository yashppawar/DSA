#ifndef _MEM_UTILS_H_
#define _MEM_UTILS_H_

#include <stdio.h>
#include <stdlib.h>

void *xcalloc(size_t, size_t);
void destroy_array(void**);

void allocate_array(size_t);

#endif
