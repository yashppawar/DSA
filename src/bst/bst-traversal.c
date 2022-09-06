#include <stdio.h>
#include "bst-traversal.h"

void preorder_r(bst_t* p_bst) {
    printf("[START]<->");
    preorder_node(p_bst -> p_root);
    puts("[END]");
}

void inorder_r(bst_t* p_bst) {
    printf("[START]<->");
    inorder_node(p_bst -> p_root);
    puts("[END]");
}

void postorder_r(bst_t* p_bst) {
    printf("[START]<->");
    postorder_node(p_bst -> p_root);
    puts("[END]");
}

void preorder_node(bst_node_t* p_node) {
    if (p_node != NULL) {
        printf("[%d]<->", p_node -> data);
        preorder_node(p_node -> left);
        preorder_node(p_node -> right);
    }
}

void inorder_node(bst_node_t* p_node) {
    if (p_node != NULL) {
        inorder_node(p_node -> left);
        printf("[%d]<->", p_node -> data);
        inorder_node(p_node -> right);
    }
}

void postorder_node(bst_node_t* p_node) {
    if (p_node != NULL) {
        postorder_node(p_node -> left);
        postorder_node(p_node -> right);
        printf("[%d]<->", p_node -> data);
    }
}
