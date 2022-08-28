#include "binary-search.h"

size_t bsearch(data_t data, data_t* p_arr, size_t size) {
    if (!isSorted(p_arr, size)) {
        return ARRAY_NOT_SORTED;
    }
    return binary_search(data, p_arr, 0, size - 1);
}

Bool find(data_t data, data_t* p_arr, size_t size) {
    if (!isSorted(p_arr, size)) {
        return ARRAY_NOT_SORTED;
    }
    return binary_search(data, p_arr, 0, size - 1) != DATA_NOT_FOUND;
}

// recursive
size_t binary_search(data_t data, data_t* p_arr, size_t start, size_t end) {
    size_t mid = (start + end) / 2;
    
    if (start >= end) {
        return DATA_NOT_FOUND;
    } else if (p_arr[mid] == data) {
        return mid;
    } else if (data < p_arr[mid]) {
        return binary_search(data, p_arr, start, mid - 1);
    } else {
        return binary_search(data, p_arr, mid + 1, end);
    }
}

// Iterative
/*
size_t binary_search(data_t data, data_t* p_arr, size_t start, size_t end) {
    size_t mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (p_arr[mid] == data) {
            return mid;
        } else if (data < p_arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return DATA_NOT_FOUND;
}
*/

static Bool isSorted(data_t* p_arr, size_t size) {
    for (size_t i = 1; i < size; i++) {
        if (p_arr[i - 1] > p_arr[i]) {
            return FALSE;
        }
    }

    return TRUE;
}
