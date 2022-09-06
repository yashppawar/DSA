#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define SUCCESS 1
#define TRUE    1

typedef int status_t;
typedef int data_t;

struct bst_node {
    data_t data;
    struct bst_node* left;
    struct bst_node* right;
    struct bst_node* parent;
};

typedef struct bst_node bst_node_t;

struct bst {
    bst_node_t* p_root;    
    size_t nr_elements;
};

typedef struct bst bst_t;

bst_t* create_bst(void);
status_t bst_insert(bst_t* p_bst, data_t new_element);
static bst_node_t* get_bst_node(data_t new_element);
void destroy_bst(bst_t** pp_bst);
void destroy_bst_node(bst_node_t* pp_node);

void preorder_node(bst_node_t* p_node);
void inorder_node(bst_node_t* p_node);
void postorder_node(bst_node_t* p_node);

void preorder_r(bst_t* p_bst);
void inorder_r(bst_t* p_bst);
void postorder_r(bst_t* p_bst);

int main(int argc, char* argv[]) {
    bst_t* p_bst = NULL;
    status_t status;
    int data[] = {100, 150, 75, 200, 125, 85, 50, 65, 130};
    int i;

    p_bst = create_bst();

    for ( i = 0; i < sizeof(data)/sizeof(data[0]); i++ ) {
        status = bst_insert(p_bst, data[i]);
        assert(status == SUCCESS);
    }

    puts("Preorder:");
    preorder_r(p_bst);

    puts("Inorder:");
    inorder_r(p_bst);

    puts("Postorder:");
    postorder_r(p_bst);

    destroy_bst(&p_bst);
}

bst_t* create_bst(void) {
    bst_t* p_bst = NULL;

    p_bst = (bst_t*) malloc(sizeof(bst_t));
    if (p_bst == NULL) {
        fprintf(stderr, "malloc:fatal:Out of Virtual Memory");
        exit(EXIT_FAILURE);
    }

    p_bst -> p_root = NULL;
    p_bst -> nr_elements = 0;

    return p_bst;
}

status_t bst_insert(bst_t* p_bst, data_t new_element) {
    bst_node_t* p_node = NULL;
    bst_node_t* p_run = p_bst -> p_root;
    p_node = get_bst_node(new_element);
    
    if ( p_bst -> p_root == NULL ) {
        p_bst -> p_root = p_node;
        return SUCCESS;
    }

    while ( TRUE ) {
        if ( new_element <= p_run -> data ) {
            if ( p_run -> left == NULL ) {
                p_run -> left = p_node;
                p_node -> parent = p_run;
                p_bst -> nr_elements += 1;
                return SUCCESS;
            }

            p_run = p_run -> left;
        } else {
            if ( p_run -> right == NULL ) {
                p_run -> right = p_node;
                p_node -> parent = p_run;
                p_bst -> nr_elements += 1;
                return SUCCESS;
            }

            p_run = p_run -> right;
        }
    }
}

static bst_node_t* get_bst_node(data_t new_element) {
    bst_node_t* p_node;

    p_node = (bst_node_t*) malloc(sizeof(bst_node_t));
    if ( p_node == NULL ) {
        fprintf(stderr, "malloc:fatal:out of virtual memory");
        exit(EXIT_FAILURE);
    }

    p_node -> left = NULL;
    p_node -> right = NULL;
    p_node -> parent = NULL;
    p_node -> data = new_element;

    return p_node;
}

void destroy_bst(bst_t** pp_bst) {
    bst_t* p_bst = *pp_bst;

    destroy_bst_node(p_bst -> p_root);

    free(p_bst);
    *pp_bst = NULL;
}

void destroy_bst_node(bst_node_t* p_node) {
    if (p_node != NULL) {
        destroy_bst_node(p_node -> left);
        destroy_bst_node(p_node -> right);
        free(p_node);
    }
}

void preorder_node(bst_node_t* p_node) {
    if ( p_node != NULL ) {
        printf("[%d]<->", p_node -> data);
        preorder_node(p_node -> left);
        preorder_node(p_node -> right);
    }
}

void inorder_node(bst_node_t* p_node) {
    if ( p_node != NULL ) {
        inorder_node(p_node -> left);
        printf("[%d]<->", p_node -> data);
        inorder_node(p_node -> right);
    }
}

void postorder_node(bst_node_t* p_node) {
    if ( p_node != NULL ) {
        postorder_node(p_node -> left);
        postorder_node(p_node -> right);
        printf("[%d]<->", p_node -> data);
    }
}

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
