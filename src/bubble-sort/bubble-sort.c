#include "bubble-sort.h"

void bsort(data_t* p_arr, size_t size) {
    size_t i, j;
    short swaps;

    for ( i = 0; i < size - 1; i++ ) {
        swaps = FALSE;

        for ( j = 1; j < (size - i); j++) {
            if ( p_arr[j - 1] > p_arr[j] ) {
                data_t temp = p_arr[j];
                p_arr[j] = p_arr[j - 1];
                p_arr[j - 1] = temp; 
                swaps = TRUE;
            }
        }

        if (!swaps) 
            break;
    }
}
