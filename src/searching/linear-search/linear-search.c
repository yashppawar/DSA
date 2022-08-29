#include "linear-search.h"

size_t lsearch(data_t data, data_t* p_arr, size_t size) {
    for ( size_t i = 0; i < size; i++ ) {
        if ( p_arr[i] == data ) 
            return i;
    }

    return DATA_NOT_FOUND;
}

Bool find(data_t data, data_t* p_arr, size_t size) {
    return lsearch(data, p_arr, size) != DATA_NOT_FOUND;
}
