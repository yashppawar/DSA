#ifndef _DCLL_H_
#define _DCLL_H_

#include <stdlib.h>

#define SUCCESS 1
#define TRUE    1
#define FALSE   0

#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY          3

typedef int data_t;
typedef int status_t;
typedef unsigned long long len_t;
typedef short bool;

struct node {
    data_t data;

    struct node* next;
    struct node* prev;
};

typedef struct node node_t;
typedef node_t list_t;

list_t* create_list();
status_t destroy_list(list_t** pp_list);
void display_list(list_t* p_list, const char* msg);

bool is_empty(list_t* p_list);
len_t get_length(list_t* p_list);
bool find(list_t* p_list, data_t f_data);

status_t insert_start(list_t* p_list, data_t new_data);
status_t insert_end(list_t* p_list, data_t new_data);
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data);
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data);

status_t get_start(list_t* p_list, data_t* data);
status_t get_end(list_t* p_list, data_t* data);
status_t pop_start(list_t* p_list, data_t* data);
status_t pop_end(list_t* p_list, data_t* data);

status_t remove_start(list_t* p_list);
status_t remove_end(list_t* p_list);
status_t remove_data(list_t* p_list, data_t r_data);

static node_t* get_node(data_t new_data);
static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end);
static void generic_delete(node_t* p_del);
static node_t* search_node(list_t* p_list, data_t s_data);

#endif
