#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "selection-sort.h"

#define TRUE  1
#define FALSE 0
#define MAX   1000

data_t* allocate_array(size_t size);
void fill_array(data_t* p_arr, size_t size);
void display_array(data_t* p_arr, size_t size, const char* msg);
void destroy_array(data_t** pp_arr);

int main(int argc, char* argv[]) {
    data_t* p_arr = NULL;
    size_t N;

    if ( argc < 2 ) {
        fprintf(stderr, "Usage error: %s num_elements", argv[0]);
        exit(EXIT_FAILURE);
    } 

    const int VERBOSE = ( argc > 2 && strcmp(argv[2], "-v") == 0 );

    srand(time(0));
    N = atoi(argv[1]);

    p_arr = allocate_array(N);
    fill_array(p_arr, N);

    if (VERBOSE) 
        display_array(p_arr, N, "Before:");    
    
    ssort(p_arr, N);

    if (VERBOSE) 
        display_array(p_arr, N, "After:");    
}

data_t* allocate_array(size_t size) {
    data_t* p_arr = NULL;

    p_arr = (data_t*)calloc(size, sizeof(data_t));
    assert(p_arr != NULL);

    return p_arr;
}

void fill_array(data_t* p_arr, size_t size) {
    for ( size_t i = 0; i < size; i++ ) {
        p_arr[i] = rand() % MAX;
    }
}

void display_array(data_t* p_arr, size_t size, const char* msg) {
    puts(msg);

    for ( size_t i = 0; i < size; i++ ) {
        printf("[%03lu] %d\n", i, p_arr[i]);
    }
}

void destory_array(data_t** pp_arr) {
    free(*pp_arr);
    pp_arr = NULL;
}
