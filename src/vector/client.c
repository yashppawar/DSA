#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

int* random_arr(size_t size);

#define N 10

int main(int argc, char* argv[])
{
    vector_t* vector = vector_create();
    int* arr = random_arr(N);

    for (size_t i = 0; i < N; i++)
        vector_append(vector, arr[i]);

    vector_display(vector, "Vector: ");

    vector_append(vector, 5);
    vector_append(vector, 6);
    vector_display(vector, "Vector: ");

    vector_destroy(&vector);
}

int* random_arr(size_t size) {
    int* arr = NULL;

    arr = (int*) calloc(size, sizeof(int));

    for (size_t i = 0; i < size; i++) 
        arr[i] = rand() % 1000;

    return arr;
}
