#include <stdio.h>
#include <stdlib.h>
#include "scll.h"

list_t *create_list() {
    list_t *p_list = NULL;

    p_list = get_node(-1);
    p_list -> next = p_list;

    return p_list; 
}

void free_list(list_t **pp_list) {
    list_t *p_list = *pp_list;
    node_t *p_run = NULL;
    node_t *p_run_next = NULL;

    p_run = p_list -> next;
    while (p_run != p_list) {
        p_run_next = p_run -> next;
        free(p_run);
        p_run = p_run_next;
    }

    free(p_list);
    *pp_list = NULL;
}

status_t display_list(list_t *p_list, const char *msg) {
    node_t *p_run = NULL;

    p_run = p_list -> next;

    printf("%s [START] ->", msg);
    while (p_run != p_list)
    {
        printf(" [%d] ->", p_run -> data);
        p_run = p_run -> next;
    }
    printf(" [END]\n");

    return (SUCCESS);
}

status_t insert_start(list_t *p_list, data_t new_data) {
    generic_insert(p_list, get_node(new_data), p_list -> next);
    return (SUCCESS);
}

static void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end) {
    p_beg -> next = p_mid;
    p_mid -> next = p_end;
}

static void get_last_node(list_t *p_list, node_t **pp_last_node) {
    node_t *p_run = NULL;
    node_t *p_run_last = NULL;

    p_run = p_list -> next;
    while (p_run != p_list) {
        p_run_last = p_run;
        p_run = p_run -> next;
    }

    *pp_last_node = p_run_last;
}

static node_t *get_node(data_t data) {
    node_t *p_node = NULL;

    p_node = (node_t*) xcalloc(1, sizeof(node_t));

    p_node -> data = data;
    p_node -> next = NULL;

    return p_node;
}

static void *xcalloc(size_t nmemb, size_t size) {
    void *ptr = NULL;

    ptr = calloc(nmemb, size);
    if (ptr == NULL) {
        fprintf(stderr, "Calloc:Fatal:Out of Virtual Memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}
