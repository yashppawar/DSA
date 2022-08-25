#include "selection-sort.h"

void ssort(data_t* p_arr, size_t size) {
    data_t temp;
    size_t idx;

    for ( size_t i = 0; i < size - 1; i++ ) {
        idx = argMin(p_arr + i, size - i) + i;  // add i for slicing, and to align the index
        temp = p_arr[idx];
        p_arr[idx] = p_arr[i];
        p_arr[i] = temp;
    }
}

static size_t argMin(data_t* p_arr, size_t size) {
    size_t idx = 0;

    for ( size_t i = 1; i < size; i++ ) {
        if (p_arr[idx] > p_arr[i]) {
            idx = i;
        }
    }

    return idx;
}
