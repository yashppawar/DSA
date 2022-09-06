#ifndef _BST_H_
#define _BST_H_

#include <stdlib.h>

#define SUCCESS 1
#define TRUE    1

typedef int data_t;
typedef int status_t;

struct bst_node {
    data_t data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

struct bst {
    struct bst_node* p_root;
    size_t nr_elements;
};

typedef struct bst_node bst_node_t;
typedef struct bst bst_t;

bst_t* create_bst(void);
void destroy_bst(bst_t** pp_bst);

status_t bst_insert(bst_t* p_bst, data_t new_data);

static void destroy_bst_node(bst_node_t* p_node);
static bst_node_t* get_bst_node(data_t data);

#endif
