#ifndef _BST_H_
#define _BST_H_

#include <stdlib.h>

#define TRUE                1
#define SUCCESS             1
#define TREE_EMPTY          2
#define TREE_DATA_NOT_FOUND 3
#define TREE_NO_SUCCESSOR   4
#define TREE_NO_PREDECESSOR 5

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
status_t bst_min(bst_t* p_bst, data_t* storage);
status_t bst_max(bst_t* p_bst, data_t* storage);
status_t bst_inorder_successor(bst_t* p_bst, data_t ext_data, data_t* p_succ_data);
status_t bst_inorder_predecessor(bst_t* p_bst, data_t ext_data, data_t* p_pred_data);
status_t bst_remove_data(bst_t* p_bst, data_t ext_data);
int bst_search(bst_t* p_bst, int search_data);

bst_node_t* get_min_node(bst_node_t* p_node);
bst_node_t* get_max_node(bst_node_t* p_node);
bst_node_t* inorder_successor(bst_node_t* p_node);
bst_node_t* inorder_predecessor(bst_node_t* p_node);
bst_node_t* search_node(bst_t* p_bst, data_t search_data);

static void destroy_bst_node(bst_node_t* p_node);
static bst_node_t* get_bst_node(data_t data);

#endif
