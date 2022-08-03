#ifndef _DCLL_LINKED_LIST_H_
#define _DCLL_LINKED_LIST_H_

#include <stdio.h>

#define SUCCESS 1
#define TRUE    1
#define FALSE   0

#define LIST_DATA_NOT_FOUND     2 
#define LIST_EMPTY              3 

typedef int data_t; 
typedef int status_t; 
typedef int len_t; 
typedef int bool; 

struct node {
    data_t data;
    struct node *next;
    struct node *prev;
};

typedef struct node node_t;
typedef node_t list_t;

/* interface functions */ 
list_t* create_list(void); 

status_t insert_start(list_t* p_list, data_t new_data); 
status_t insert_end(list_t* p_list, data_t new_data); 
status_t insert_after(list_t* p_list, data_t e_data, data_t new_data); 
status_t insert_before(list_t* p_list, data_t e_data, data_t new_data); 

status_t get_start(list_t* p_list, data_t* p_start_data); 
status_t get_end(list_t* p_list, data_t* p_end_data); 
status_t pop_start(list_t* p_list, data_t* p_start); 
status_t pop_end(list_t* p_list, data_t* p_end_data); 

status_t remove_start(list_t* p_list); 
status_t remove_end(list_t* p_list); 
status_t remove_data(list_t* p_data, data_t r_data); 

bool is_empty(list_t* p_list); 
bool find(list_t* p_list, data_t f_data); 
len_t get_length(list_t* p_list); 
void show(list_t* p_list, const char* msg); 

status_t destroy_list(list_t** pp_list); 

/* concat immuable */ 
list_t* concat_lists_imm(list_t* p_list_1, list_t* p_list_2); 
// void concat_lists_imm(list_t* p_list, list_t* p_list_2, list_t** pp_list); 
/* concat mutable */
status_t concat_list_m(list_t* p_list_1, list_t* p_list_2); 

/* merge sorted lists */ 
list_t* merge_lists(list_t* p_list_1, list_t* p_list_2); 

/* reversal */ 
/* immutable */ 
list_t* get_reversed_list(list_t* p_list);  /* immutable version */ 
status_t reverse_list(list_t* p_list);      /* mutable version */ 

/* list axuillary functions */ 

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end); 
static void generic_delete(node_t* p_delete_node); 
static node_t* search_node(list_t* p_list, data_t s_data); 
static node_t* get_node(data_t new_data); 

/* auxillary function */ 
static void* xcalloc(size_t nr_elements, size_t size_per_element); 

#endif
