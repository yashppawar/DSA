#ifndef _SINGLY_CIRCULAR_LINKED_LIST_H_
#define _SINGLY_CIRCULAR_LINKED_LIST_H_

#include <stdlib.h>

#define SUCCESS 1
#define TRUE    1
#define FALSE   0

// Errors
#define LIST_EMPTY          2
#define LIST_DATA_NOT_FOUND 3

// Data types
typedef int data_t;
typedef int status_t;
typedef int len_t;
typedef short bool;

struct node {
    data_t data;
    struct node *next;
};

typedef struct node node_t;
typedef node_t list_t;

list_t *create_list();
void free_list(list_t **pp_list);
status_t display_list(list_t* p_list, const char *msg);

status_t insert_start(list_t *p_list, data_t new_data);
status_t insert_end(list_t *p_list, data_t new_data);

// auxillary functions
static void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end);
static void get_last_node(list_t* p_list, node_t** pp_last_node);
static void get_last_node_and_prev(list_t* p_list, node_t** pp_node, node_t** pp_prev_node);
static node_t *get_node(data_t data);
static void *xcalloc(size_t nmemb, size_t size);

#endif
