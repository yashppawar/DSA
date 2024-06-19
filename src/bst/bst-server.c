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

status_t bst_inorder_successor(bst_t* p_bst, data_t ext_data, data_t* p_succ_data) {
    bst_node_t* p_ext_data = NULL; // existing data
    bst_node_t* p_succ = NULL;

    p_ext_data = search_node(p_bst, ext_data);
    if (p_ext_data == NULL) 
        return (TREE_DATA_NOT_FOUND);

    p_succ = inorder_successor(p_ext_data);
    if (p_succ == NULL)
        return (TREE_NO_SUCCESSOR);

    *p_succ_data = p_succ -> data;
    return (SUCCESS);
}

status_t bst_inorder_predecessor(bst_t* p_bst, data_t ext_data, data_t* p_pred_data) {
    bst_node_t* p_ext_data = NULL;
    bst_node_t* p_pred = NULL;

    p_ext_data = search_node(p_bst, ext_data);
    if (p_ext_data == NULL)
        return (TREE_DATA_NOT_FOUND);

    p_pred = inorder_predecessor(p_ext_data);
    if (p_pred == NULL)
        return (TREE_NO_PREDECESSOR);

    *p_pred_data = p_pred -> data;
    return (SUCCESS);
}

status_t bst_remove_data(bst_t* p_bst, data_t ext_data) {
    bst_node_t* p_remove_node = NULL;
    bst_node_t* p_run = NULL;

    p_remove_node = search_node(p_bst, ext_data);
    if (p_remove_node == NULL)
        return (TREE_DATA_NOT_FOUND);

    if (p_remove_node -> left == NULL) {
        if (p_remove_node -> parent == NULL) {
            p_bst -> p_root = p_remove_node -> right;
        } 
        else if (p_remove_node == p_remove_node -> parent -> left) {
            p_remove_node -> parent -> left = p_remove_node -> right;
        } 
        else {
            p_remove_node -> parent -> right = p_remove_node -> right;
        } 

        if (p_remove_node -> right != NULL) 
            p_remove_node -> right -> parent = p_remove_node -> parent;
    } 
    else if (p_remove_node -> right = NULL) {
        if (p_remove_node -> parent == NULL) {
            p_bst -> p_root = p_remove_node -> left;
        }
        else if (p_remove_node == p_remove_node -> parent -> left) 
            p_remove_node -> parent -> left = p_remove_node -> left;
        else 
            p_remove_node -> parent -> right = p_remove_node -> left;

        if (p_remove_node -> left != NULL) 
            p_remove_node -> left -> parent = p_remove_node -> parent;
    }
    else {
        p_run = p_remove_node -> right;

        while (p_run -> left != NULL) 
            p_run = p_run -> left;

        if (p_run != p_remove_node -> right) {
            p_run -> parent -> left = p_run -> right;
            
            if (p_run -> right != NULL)
                p_run -> right -> parent = p_run -> parent;

            p_run -> right = p_remove_node -> right;
            p_remove_node -> right -> parent = p_run;
        }

        if (p_remove_node -> parent == NULL)
            p_bst -> p_root = p_run;
        
        else if (p_remove_node -> parent -> left == p_remove_node)
            p_remove_node -> parent -> left = p_run;
        else 
            p_remove_node -> parent -> right = p_run;

        p_run -> parent = p_remove_node -> parent;

        p_run -> left = p_remove_node -> left;
        p_remove_node -> left -> parent = p_run;
    }

    free(p_remove_node);
    p_remove_node = NULL;

    return (SUCCESS);
}

int bst_search(bst_t* p_bst, data_t search_data) {
    return (search_node(p_bst, search_data) != NULL);
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

bst_node_t* inorder_successor(bst_node_t* p_node) {
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;

    if ( p_node -> right != NULL ) {
        return get_min_node(p_node -> right);
    } else {
        x = p_node;
        y = x -> parent;

        while ( y != NULL && y -> right == x ) {
            x = y;
            y = y -> parent;
        }

        return y;
    }
}

bst_node_t* inorder_predecessor(bst_node_t* p_node) {
    bst_node_t* p_run = NULL;
    bst_node_t* x = NULL;
    bst_node_t* y = NULL;

    if (p_node -> left != NULL) {
        return get_max_node(p_node -> left);
    } else {
        x = p_node;
        y = x -> parent;

        while ( y != NULL && y -> left == x ) {
            x = y;
            y = x -> parent;
        }

        return y;
    }
}

bst_node_t* search_node(bst_t* p_bst, data_t search_data) {
    bst_node_t* p_run = NULL;

    p_run = p_bst -> p_root;

    while ( p_run != NULL ) {
        if ( p_run -> data == search_data ) 
            return p_run;

        if ( p_run -> data > search_data )
            p_run = p_run -> left;
        else 
            p_run = p_run -> right;
    }

    return (NULL);
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
