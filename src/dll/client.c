#include <stdio.h>
#include <assert.h>
#include "dll.h"

int main(int argc, char* argv[]) {
    list_t* p_list = NULL;
    list_t* p_reversed_list = NULL;
    list_t* p_list1 = NULL;
    list_t* p_list2 = NULL;
    list_t* p_concat_list = NULL;
    list_t* p_merged_list = NULL;
    int data;
    status_t status;

    p_list = create_list();

    assert(p_list != NULL);
    display_list(p_list, "After Creation: ");
    
    assert(is_empty(p_list) == TRUE);
    assert(get_length(p_list) == 0);
    assert(get_start(p_list, &data) == LIST_EMPTY);
    assert(get_end(p_list, &data) == LIST_EMPTY);
    assert(pop_start(p_list, &data) == LIST_EMPTY);
    assert(pop_end(p_list, &data) == LIST_EMPTY);
    assert(remove_start(p_list) == LIST_EMPTY);
    assert(remove_end(p_list) == LIST_EMPTY);

    for ( data = 0; data < 5; data++ )
        assert(insert_start(p_list, data) == SUCCESS);
    display_list(p_list, "After insert_start(): ");
    
    for ( data = 0; data < 5; data++ )
        assert(insert_end(p_list, data) == SUCCESS);
    display_list(p_list, "After insert_end(): ");

    assert(insert_after(p_list, -10, 100) == LIST_DATA_NOT_FOUND);
    assert(insert_before(p_list, 100, 200) == LIST_DATA_NOT_FOUND);

    assert(insert_after(p_list, 0, 100) == SUCCESS);
    display_list(p_list, "After insert_after(): ");
    assert(insert_before(p_list, 0, 100) == SUCCESS);
    display_list(p_list, "After insert_before(): ");
    
    assert(get_length(p_list) > 0);
    data = -1;
    assert(get_start(p_list, &data) == SUCCESS);
    printf("Start Data: %d\n", data);
    
    data = -1;
    assert(get_end(p_list, &data) == SUCCESS);
    printf("End Data: %d\n", data);

    data = -1;
    assert(pop_start(p_list, &data) == SUCCESS);
    printf("Start Data: %d\n", data);
    display_list(p_list, "After pop_start(): ");

    data = -1;
    assert(pop_end(p_list, &data) == SUCCESS);
    printf("End Data: %d\n", data);
    display_list(p_list, "After pop_end(): ");

    assert(remove_start(p_list) == SUCCESS);
    display_list(p_list, "After remove_start(): ");

    assert(remove_end(p_list) == SUCCESS);
    display_list(p_list, "After remove_end(): ");
    
    assert(remove_data(p_list, 314) == LIST_DATA_NOT_FOUND);
    assert(remove_data(p_list, 0) == SUCCESS);
    display_list(p_list, "After remove_data(): ");
    
    printf("Length = %llu\n", get_length(p_list));
    assert(is_empty(p_list) == FALSE);

    if (find(p_list, -10) == FALSE)
        puts("-10 is not in the list");

    if (find(p_list, 2) == TRUE)
        puts("2 is in the list");



    destroy_list(&p_list);
    return 0;
}