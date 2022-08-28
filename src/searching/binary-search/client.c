#include <stdio.h>
#include <assert.h>
#include "binary-search.h"

int main(int argc, char* argv[]) {
    data_t arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_t arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_t arr3[10] = {1, 6, 2, 4, 5, 7, 7, 6, 9, 17};

    assert(find(0, arr3, 10) == ARRAY_NOT_SORTED);
    assert(bsearch(0, arr3, 10) == ARRAY_NOT_SORTED);

    assert(find(17, arr1, 10) == FALSE);
    assert(find(17, arr2, 9) == FALSE);
    assert(bsearch(17, arr1, 10) == DATA_NOT_FOUND);
    assert(bsearch(17, arr2, 9) == DATA_NOT_FOUND);
    
    assert(find(7, arr1, 10) == TRUE);
    assert(find(5, arr1, 10) == TRUE);
    assert(find(3, arr2, 9) == TRUE);

    assert(bsearch(7, arr1, 10) == 7);
    assert(bsearch(3, arr2, 9) == 2);
}
