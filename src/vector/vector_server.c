#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "vector.h"

vector_t* vector_create()
{
    vector_t* vector = (vector_t*) calloc(1, sizeof(vector_t));
    assert(vector != NULL);

    vector -> size = 0;
    vector -> data = NULL;

    return vector;
}

void vector_destroy(vector_t** pp_vector)
{
    vector_t *p_vec = *pp_vector;

    free(p_vec -> data);
    free(p_vec);
    *pp_vector = NULL;
}

status_t vector_append(vector_t* vector, data_t data)
{
    assert(vector != NULL);

    vector -> data = (data_t*) realloc(vector -> data, (vector -> size + 1) * sizeof(data_t));
    assert(vector -> data != NULL);

    vector -> data[vector -> size] = data;
    vector -> size++;

    return (SUCCESS);
}

void vector_display(vector_t* vector, const char* message)
{
    assert(vector != NULL);

    puts(message);

    for (int i = 0; i < vector -> size; i++)
    {
        printf("%d, ", vector -> data[i]);
    }

    printf("\n");
}
