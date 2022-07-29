#include <stdio.h>
#include "vector.h"

int main(int argc, char* argv[])
{
    vector_t* vector = vector_create();
    
    vector_append(vector, 1);
    vector_append(vector, 2);
    vector_append(vector, 3);
    vector_append(vector, 4);

    vector_display(vector, "Vector: ");

    vector_append(vector, 5);
    vector_append(vector, 6);
    vector_display(vector, "Vector: ");

    vector_destroy(&vector);
}