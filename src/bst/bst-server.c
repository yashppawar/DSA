#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

bst_t* create_bst(void) {
    bst_t* p_bst = NULL;

    p_bst = (bst_t*) malloc(sizeof(bst_t));
    if (p_bst == NULL) {
        fprintf(stderr, "fatal:malloc:Out Of Virtual Memory");
        exit(EXIT_FAILURE);
    }

    p_bst -> p_root = NULL;
    p_bst -> nr_elements = 0;

    return p_bst;
}

void destroy_bst(bst_t** pp_bst) {
    bst_t* p_bst = *pp_bst;

    destroy_bst_node(p_bst -> p_root);

    free(p_bst);
    *pp_bst = NULL;
}

status_t bst_insert(bst_t* p_bst, data_t new_data) {
    bst_node_t* p_run = NULL;
    bst_node_t* p_node = NULL;
    p_node = get_bst_node(new_data);

    if (p_bst -> p_root == NULL) {
        p_bst -> p_root = p_node;
        return (SUCCESS);
    }

    p_run = p_bst -> p_root;
    while (TRUE) {
        if (new_data <= p_run -> data) {
            if (p_run -> left == NULL) {
                p_run -> left = p_node;
                p_node -> parent = p_run;
                p_bst -> nr_elements++;
                return (SUCCESS);
            }

            p_run = p_run -> left;
        } else {
            if (p_run -> right == NULL) {
                p_run -> right = p_node;
                p_node -> parent = p_run;
                p_bst -> nr_elements++;
                return (SUCCESS);
            }

            p_run = p_run -> right;
        }
    }
}

status_t bst_min(bst_t* p_bst, data_t* storage) {
    bst_node_t* p_node = NULL;

    if (p_bst -> p_root == NULL)
        return (TREE_EMPTY);

    p_node = get_min_node(p_bst -> p_root);
    *storage = p_node -> data;
    return (SUCCESS);
}

status_t bst_max(bst_t* p_bst, data_t* storage) {
    bst_node_t* p_node = NULL;

    if (p_bst -> p_root == NULL)
        return (TREE_EMPTY);

    p_node = get_max_node(p_bst -> p_root);
    *storage = p_node -> data;
    return (SUCCESS);
}

bst_node_t* get_min_node(bst_node_t* p_node) {
    bst_node_t* p_run = NULL;

    p_run = p_node;
    while ( p_run -> left != NULL ) 
        p_run = p_run -> left;

    return p_run;
}

bst_node_t* get_max_node(bst_node_t* p_node) {
    bst_node_t* p_run = NULL;

    p_run = p_node;
    while ( p_run -> right != NULL ) 
        p_run = p_run -> right;

    return p_run;
}

static void destroy_bst_node(bst_node_t* p_node) {
    if (p_node != NULL) {
        destroy_bst_node(p_node -> left);
        destroy_bst_node(p_node -> right);
        free(p_node);
    }
}

static bst_node_t* get_bst_node(data_t data) {
    bst_node_t* p_node = NULL;

    p_node = (bst_node_t*) malloc(sizeof(bst_node_t));
    if (p_node == NULL) {
        fprintf(stderr, "fatal:malloc:Out of virtual memory");
        exit(EXIT_FAILURE);
    }

    p_node -> data = data;
    p_node -> left = NULL;
    p_node -> right = NULL;
    p_node -> parent = NULL;

    return p_node;
}
