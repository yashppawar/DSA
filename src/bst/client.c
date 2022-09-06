#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"
#include "bst-traversal.h"

data_t* allocate_array(size_t size);
void fill_array(data_t* p_arr, size_t size);
int random_int(int min, int max);

int main(int argc, char* argv[]) {
    size_t N, i;
    data_t* p_arr = NULL;
    bst_t* p_bst = NULL;

    if ( argc < 2 ) {
        fprintf(stderr, "Usage Error: correct usage -> $ %s num_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    N = atoi(argv[1]);
    p_arr = allocate_array(N);
    fill_array(p_arr, N);

    p_bst = create_bst();

    for (i = 0; i < N; i++) {
        bst_insert(p_bst, p_arr[i]);
    }

    puts("PreOrder:");
    preorder_r(p_bst);

    puts("InOrder:");
    inorder_r(p_bst);

    puts("PostOrder:");
    postorder_r(p_bst);

    free(p_arr);
    p_arr = NULL;
    destroy_bst(&p_bst);
    puts("SUCCESS");
}

data_t* allocate_array(size_t size) {
    data_t* p_arr = NULL;

    p_arr = (data_t*) calloc(size, sizeof(data_t));
    if (p_arr == NULL) {
        fprintf(stderr, "fatal:calloc:Out of Virtual Memory\n");
        exit(EXIT_FAILURE);
    }

    return p_arr;
}

void fill_array(data_t* p_arr, size_t size) {
    size_t i;

    for (i = 0; i < size; i++) {
        p_arr[i] = random_int((int)-size, (int)size);
    }
}

int random_int(int min, int max) {
    return (rand() % (max - min)) + min;
}
