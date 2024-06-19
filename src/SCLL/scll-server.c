#include <stdio.h>
#include <assert.h>
#include "scll.h"

int main(int argc, char* argv[]) {
    list_t *p_list = NULL;

    p_list = create_list();
    assert(p_list != NULL);

    display_list(p_list, "After Creation: ");
    
    free_list(&p_list);
    assert(p_list == NULL);

    return 0;
}
