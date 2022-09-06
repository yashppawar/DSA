#include <stdio.h>
#include <assert.h>
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
    data_t storage, s_data;
    bst_t* p_bst = NULL;
    status_t status;

    if ( argc < 2 ) {
        fprintf(stderr, "Usage Error: correct usage -> $ %s num_elements\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    srand(time(0));
    N = atoi(argv[1]);
    p_arr = allocate_array(N);
    fill_array(p_arr, N);

    p_bst = create_bst();

    status = bst_max(p_bst, &storage); 
    if(status == TREE_EMPTY)
        printf("bst_max:Tree is empty\n"); 

    status = bst_min(p_bst, &storage); 
    if(status == TREE_EMPTY)
        printf("bst_min:Tree is empty\n"); 

    for (i = 0; i < N; i++) {
        bst_insert(p_bst, p_arr[i]);
    }

    puts("PreOrder:");
    preorder_r(p_bst);

    puts("InOrder:");
    inorder_r(p_bst);

    puts("PostOrder:");
    postorder_r(p_bst);

    assert(bst_min(p_bst, &storage) == SUCCESS);
    printf("Min: %d\n", storage);

    assert(bst_max(p_bst, &storage) == SUCCESS);
    printf("Max: %d\n", storage);

    for ( i = 0; i < 5; i++ ) {
        s_data = random_int(N, 2 * N);
        printf("%d present in bst? : %s\n", s_data, bst_search(p_bst, s_data) ? "TRUE" : "FALSE");
    } 

    for ( i = 0; i < 5; i++ ) {
        s_data = p_arr[i];
        printf("%d present in bst? : %s\n", s_data, bst_search(p_bst, s_data) ? "TRUE" : "FALSE");
    } 

    for ( i = 0; i < N; i++ ) {
        s_data = p_arr[i];
        
        status = bst_inorder_predecessor(p_bst, s_data, &storage); 
        if(status == TREE_NO_PREDECESSOR)
            printf("%d has no predecessor\n", s_data); 
        else if(status == SUCCESS)
            printf("Predecessor of %d is %d\n", s_data, storage);
        else if(status == TREE_DATA_NOT_FOUND) 
            printf("%d Not in TREE\n", s_data);
    } 

    for ( i = 0; i < N; i++ ) {
        s_data = p_arr[i];

        status = bst_inorder_successor(p_bst, s_data, &storage); 
        if(status == TREE_NO_SUCCESSOR)
            printf("%d has no successor\n", s_data); 
        else if(status == SUCCESS)
            printf("successor of %d is %d\n", s_data, storage);
        else if(status == TREE_DATA_NOT_FOUND) 
            printf("%d Not in TREE\n", s_data);
    } 

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
