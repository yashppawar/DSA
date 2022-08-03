#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linked-list.h"

list_t* create_list(void) {
    list_t* p_list = NULL;

    p_list = get_node(-1);
    p_list -> next = p_list;
    p_list -> prev = p_list;

    return p_list;
}

// Insert functions
status_t insert_start(list_t* p_list, data_t new_data) {
    generic_insert(p_list, get_node(new_data), p_list -> next);
    return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data) {
    generic_insert(p_list -> prev, get_node(new_data), p_list);
    return (SUCCESS);
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data) {
    node_t* e_node = NULL;

    e_node = search_node(p_list, e_data);
    if (e_node == NULL) 
        return (LIST_DATA_NOT_FOUND);

    generic_insert(e_node, get_node(new_data), e_node -> next);
    return (SUCCESS);
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data) {
    node_t* e_node = NULL;

    e_node = search_node(p_list, e_data);
    if (e_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_insert(e_node -> prev, get_node(new_data), e_node);
    return (SUCCESS);
}

// Get data
status_t get_start(list_t* p_list, data_t* p_start_data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *p_start_data = p_list -> next -> data;
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* p_end_data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *p_end_data = p_list -> prev -> data;
    return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* p_start_data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *p_start_data = p_list -> next -> data;
    generic_delete(p_list -> next);

    return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* p_end_data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *p_end_data = p_list -> prev -> data;
    generic_delete(p_list -> prev);
    
    return (SUCCESS);
}

status_t remove_start(list_t* p_list) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    generic_delete(p_list -> next);
    return (SUCCESS);
}

status_t remove_end(list_t* p_list) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    generic_delete(p_list -> prev);
    return (SUCCESS);
} 

status_t remove_data(list_t* p_list, data_t r_data) {
    node_t* p_remove = NULL;

    if (is_empty(p_list))
        return (LIST_EMPTY);

    p_remove = search_node(p_list, r_data);
    if (p_remove == NULL) 
        return (LIST_DATA_NOT_FOUND);

    generic_delete(p_remove);
    return (SUCCESS);    
}

bool is_empty(list_t* p_list) {
    return (p_list == p_list -> next && p_list == p_list -> prev);
}

bool find(list_t* p_list, data_t f_data) {
    node_t* p_find = NULL;

    p_find = search_node(p_list, f_data);
    return (p_find != NULL);
}

len_t get_length(list_t* p_list) {
    node_t* p_run;
    len_t len = 0;

    for (p_run = p_list -> next; p_run != p_list; p_run = p_run -> next, ++len);

    return len;
}

void show(list_t* p_list, const char* msg) {
    node_t* p_run;

    printf("%s\n", msg);
    printf("[START]<=>");
    for (p_run = p_list -> next; p_run != p_list; p_run = p_run -> next) 
        printf("[%d]<=>", p_run -> data);

    printf("[END]\n");
}

status_t destroy_list(list_t** pp_list) {
    list_t* p_list = NULL;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_list = *pp_list;
    p_run = p_list -> next;
    while (p_run != p_list) {
        p_run_next = p_run -> next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);
    p_list = NULL;

    *pp_list = NULL;
    return (SUCCESS);
}

list_t* concat_lists_imm(list_t* p_list_1, list_t* p_list_2) {
    list_t* p_concat_List = NULL;
    node_t* p_run;

    p_concat_List = create_list();
    for (p_run = p_list_1 -> next; p_run != p_list_1; p_run = p_run -> next)
        assert(insert_end(p_concat_List, p_run -> data) == SUCCESS);
    for (p_run = p_list_2 -> next; p_run != p_list_2; p_run = p_run -> next)
        assert(insert_end(p_concat_List, p_run -> data) == SUCCESS);

    return p_concat_List;
}

status_t concat_list_m(list_t* p_list_1, list_t* p_list_2) {
    if (is_empty(p_list_2))
        return (SUCCESS);

    p_list_1 -> prev -> next = p_list_2 -> next;
    p_list_2 -> next -> prev = p_list_1 -> prev;
    p_list_2 -> prev -> next = p_list_1;
    p_list_1 -> prev = p_list_2 -> prev;

    free(p_list_2);
    p_list_2 = NULL;
    return SUCCESS;
}

list_t* merge_lists(list_t* p_list_1, list_t* p_list_2) {
    node_t* p_run_1  = NULL;
    node_t* p_run_2  = NULL;
    list_t* p_merged = NULL;

    p_merged = create_list();
    p_run_1 = p_list_1 -> next;
    p_run_2 = p_list_2 -> next;

    while (TRUE) {
        if (p_run_1 == p_list_1) {
            while (p_run_2 != p_list_2) {
                assert(insert_end(p_merged, p_run_2 -> data) == SUCCESS);
                p_run_2 = p_run_2 -> next;
            }
            break;
        }

        if (p_run_2 == p_list_2) {
            while (p_run_1 != p_list_1) {
                assert(insert_end(p_merged, p_run_1 -> data) == SUCCESS);
                p_run_1 = p_run_1 -> next;
            }
            break;
        }

        if (p_run_1 -> data < p_run_2 -> data) {
            assert(insert_end(p_merged, p_run_1 -> data) == SUCCESS);
            p_run_1 = p_run_1 -> next;
        } else {
            assert(insert_end(p_merged, p_run_2 -> data) == SUCCESS);
            p_run_2 = p_run_2 -> next;
        }
    }

    return p_merged;
}

list_t* get_reversed_list(list_t* p_list) {
    node_t* p_run;
    list_t* p_reversed;

    p_reversed = create_list();
    for (p_run = p_list -> next; p_run != p_list; p_run = p_run -> next) 
        assert(insert_start(p_reversed, p_run -> data) == SUCCESS);

    return p_reversed;
}

status_t reverse_list(list_t* p_list) {
    node_t* p_original_prev = NULL; 
    node_t* p_current_last = NULL; 
    node_t* p_run = NULL; 
    node_t* p_run_prev = NULL; 

    p_original_prev = p_list -> prev;
    p_current_last = p_original_prev;
    p_run = p_list -> next;

    while (p_run != p_list) {
        p_run_prev = p_run -> prev;
        p_current_last -> next = p_run; 
        p_run -> prev = p_current_last; 
        p_current_last = p_run; 
        p_run = p_run_prev; 
    }

    p_current_last -> next = p_list; 
    p_list -> prev = p_current_last;  
    p_list -> next = p_original_prev;
    p_original_prev -> prev = p_list;  
  
    return (SUCCESS);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) {
    p_beg -> next = p_mid;
    p_mid -> prev = p_beg;
    p_mid -> next = p_end;
    p_end -> prev = p_mid;
}

static void generic_delete(node_t* p_delete_node) {
    p_delete_node -> prev -> next = p_delete_node -> next;
    p_delete_node -> next -> prev = p_delete_node -> prev;

    free(p_delete_node);
    p_delete_node = NULL;
}

static node_t* search_node(list_t* p_list, data_t s_data) {
    node_t* p_run = NULL;
    p_run = p_list -> next;

    while (p_run != p_list) {
        if (p_run -> data == s_data)
            return p_run;
        p_run = p_run -> next;
    }

    return (NULL);
}

static node_t* get_node(data_t new_data) {
    node_t* node = NULL;

    node = (node_t*) xcalloc(1, sizeof(node_t));
    node -> data = new_data;
    node -> next = NULL;
    node -> prev = NULL;

    return node;
}

static void* xcalloc(size_t nr_elements, size_t size_per_elememt) {
    void* ptr = calloc(nr_elements, size_per_elememt);

    if (ptr == NULL) {
        fprintf(stderr, "Calloc: Fatal: Out of Virtual Memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
