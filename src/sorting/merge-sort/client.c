#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "merge-sort.h"
#include "memutils.h"

int VERBOSE;

void fill_array(data_t*, size_t);
void display_array(data_t* p_arr, size_t size, const char* msg);

int main(int argc, char* argv[])
{
    data_t* p_arr = NULL;
    size_t N;

    if ( argc < 2 )
    {
        fprintf(stderr, "Usage Error: correct usage -> %s num_items [-v]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    VERBOSE = ( argc > 2 && strcmp(argv[2], "-v") == 0 );

    srand(time(0));
    N = atoi(argv[1]);
    p_arr = (data_t*) xcalloc(N, sizeof(data_t));
    fill_array(p_arr, N);

    if (VERBOSE)
        display_array(p_arr, N, "Before Sort:");

    msort(p_arr, N);

    if (VERBOSE)
        display_array(p_arr, N, "After Sort: ");

    destroy_array(&p_arr);
    exit(EXIT_SUCCESS);
}

void fill_array(data_t* arr, size_t length)
{
    for ( int i = 0; i < length; i++ )
        arr[i] = rand();
}

void display_array(data_t* p_arr, size_t size, const char* msg) {
    puts(msg);

    for ( size_t i = 0; i < size; i++ )
        printf("[%03lu] %d\n", i, p_arr[i]);   
}
