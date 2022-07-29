#ifndef _vector_h_
#define _vector_h_

#include <stdio.h>

#define SUCCESS 0
#define FAILURE 1

typedef int data_t;
typedef int status_t;

typedef struct tagVector 
{
    size_t size;
    data_t* data;
} vector_t;

vector_t* vector_create();
void vector_destroy(vector_t** vector);

status_t vector_append(vector_t* vector, data_t data);
void vector_display(vector_t* vector, const char* message);

#endif