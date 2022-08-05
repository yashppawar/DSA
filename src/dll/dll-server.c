#include <stdlib.h>
#include <stdio.h>
#include "dll.h"

list_t* create_list() {
    list_t* p_list = NULL;

    p_list = get_node(-1);

    return p_list;
}

status_t destroy_list(list_t** pp_list) {
    list_t* p_list = *pp_list;
    node_t* p_run = NULL;
    node_t* p_run_next = NULL;

    p_run = p_list -> next;

    while (p_run != NULL) {
        p_run_next = p_run -> next;
        free(p_run);

        p_run = p_run_next;
    }

    free(p_list);
    *pp_list = NULL;

    return (SUCCESS);
}

void display_list(list_t* p_list, const char* msg) {
    node_t* p_run = NULL;

    p_run = p_list -> next;

    printf("%s [START] <=> ", msg);

    while (p_run != NULL) {
        printf("[%d] <=> ", p_run -> data);
        p_run = p_run -> next;        
    }
    printf("[END]\n");
}

bool is_empty(list_t* p_list) {
    return (p_list -> next == NULL);
}

len_t get_length(list_t* p_list) {
    len_t length = 0;

    for(node_t* p_run = p_list -> next; p_run != NULL; length++, p_run = p_run -> next);

    return length;
}

bool find(list_t* p_list, data_t f_data) {
    return search_node(p_list, f_data) != NULL;
}

status_t insert_start(list_t* p_list, data_t new_data) {
    generic_insert(p_list, get_node(new_data), p_list -> next);
    return (SUCCESS);
}

status_t insert_end(list_t* p_list, data_t new_data) {
    node_t* last_node = NULL;
    node_t* p_run = NULL;

    p_run = p_list -> next;

    while (p_run != NULL) {
        last_node = p_run;
        p_run = p_run -> next;
    }

    generic_insert(last_node, get_node(new_data), NULL);
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

status_t get_start(list_t* p_list, data_t* data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *data = p_list -> next -> data;
    return (SUCCESS);
}

status_t get_end(list_t* p_list, data_t* data) {
    if (is_empty(p_list)) 
        return (LIST_EMPTY);

    node_t* last = NULL;
    node_t* p_run = p_list -> next;

    while (p_run != NULL) {
        last = p_run;
        p_run = p_run -> next;
    }

    *data = last -> data;
    return (SUCCESS);
}

status_t pop_start(list_t* p_list, data_t* data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    *data = p_list -> next -> data;
    generic_delete(p_list -> next);

    return (SUCCESS);
}

status_t pop_end(list_t* p_list, data_t* data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    node_t* last = NULL;
    node_t* p_run = p_list -> next;

    while (p_run != NULL) {
        last = p_run;
        p_run = p_run -> next;
    }

    *data = last -> data;
    generic_delete(last);

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

    node_t* last = NULL;
    node_t* p_run = p_list -> next;

    while (p_run != NULL) {
        last = p_run;
        p_run = p_run -> next;
    }

    generic_delete(last);
    return (SUCCESS);
}

status_t remove_data(list_t* p_list, data_t r_data) {
    if (is_empty(p_list))
        return (LIST_EMPTY);

    node_t* s_node = search_node(p_list, r_data);

    if (s_node == NULL)
        return (LIST_DATA_NOT_FOUND);

    generic_delete(s_node);

    return (SUCCESS);
}

static node_t* get_node(data_t new_data) {
    node_t* p_node = NULL;

    p_node = (node_t*) malloc(sizeof(node_t));

    if (p_node == NULL) {
        fprintf(stderr, "malloc:fatal:Out of Virtual Memory\n");
        exit(EXIT_FAILURE);
    }

    p_node -> data = new_data;
    p_node -> next = NULL;
    p_node -> prev = NULL;

    return p_node;
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end) {
    p_mid -> prev = p_beg;
    p_mid -> next = p_end;

    if (p_beg != NULL)
        p_beg -> next = p_mid;
    if (p_end != NULL)
        p_end -> prev = p_mid;
}

static void generic_delete(node_t* p_del) {
    if (p_del == NULL)
        return;

    if (p_del -> prev != NULL)
        p_del -> prev -> next = p_del -> next;
    if (p_del -> next != NULL)
        p_del -> next -> prev = p_del -> prev;

    free(p_del);
    p_del = NULL;
}

static node_t* search_node(list_t* p_list, data_t s_data) {
    node_t* p_run = NULL;

    p_run = p_list -> next;

    while (p_run != NULL) {
        if (p_run -> data == s_data) {
            break;
        }

        p_run = p_run -> next;
    }

    return p_run;
}
