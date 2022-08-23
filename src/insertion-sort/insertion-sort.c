#include "insertion-sort.h"

void isort(data_t* p_arr, size_t size) {
    int i, j;
    data_t key;

    for ( j = 1; j < size; j++ ) {
        key = p_arr[j];
        
        i = j - 1;
        while (i >= 0 && key < p_arr[i]) {
            p_arr[i + 1] = p_arr[i];
            i--;
        }

        p_arr[i + 1] = key;
    }
}
