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

/*
size_t binarySearch(data_t* p_arr, data_t data, size_t start, size_t end) {
    size_t mid = (start + end) / 2;
    if ( end <= start )
        return ( data > p_arr[start] ) ? ( start + 1 ) : start;

    if ( p_arr[mid] == data ) 
        return mid + 1;
    
    if ( data > p_arr[mid] )
        return binarySearch(p_arr, data, mid + 1, end);
    return binarySearch(p_arr, data, start, mid - 1);
}

void isort(data_t* p_arr, size_t size) {
    size_t i, j, loc;
    data_t key;

    for ( j = 1; j < size; j++ ) {
        key = p_arr[j];

        i = j - 1;
        loc = binarySearch(p_arr, key, 0, i);

        printf("%d\n", loc);
        while (i >= loc) {
            p_arr[i + 1] = p_arr[i];
            i--;
        }

        p_arr[i + 1] = key;
    }
}
*/
