#include <stdio.h>
#include <assert.h>
#include "linear-search.h"

int main(int argc, char* argv[]) {
    data_t arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_t arr2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    data_t arr3[10] = {1, 6, 2, 4, 5, 7, 7, 6, 9, 17};

    assert(find(17, arr1, 10) == FALSE);
    assert(find(17, arr2, 9) == FALSE);
    assert(find(13, arr3, 10) == FALSE);
    
    assert(find(7, arr1, 10) == TRUE);
    assert(find(5, arr1, 10) == TRUE);
    assert(find(3, arr2, 9) == TRUE);
    assert(find(17, arr3, 10) == TRUE);
    assert(find(2, arr3, 10) == TRUE);

    assert(lsearch(17, arr1, 10) == DATA_NOT_FOUND);
    assert(lsearch(17, arr2, 10) == DATA_NOT_FOUND);
    assert(lsearch(13, arr3, 9) == DATA_NOT_FOUND);
    assert(lsearch(7, arr1, 10) == 7);
    assert(lsearch(3, arr2, 9) == 2);
    assert(lsearch(4, arr3, 10) == 3);
}
