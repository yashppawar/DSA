#ifndef _BST_RAVERSAL_H_
#define _BST_RAVERSAL_H_

#include "bst.h"

void preorder_r(bst_t* p_bst);
void inorder_r(bst_t* p_bst);
void postorder_r(bst_t* p_bst);

void preorder_node(bst_node_t* p_node);
void inorder_node(bst_node_t* p_node);
void postorder_node(bst_node_t* p_node);

#endif
