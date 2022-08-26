#include <limits.h>
#include <assert.h>
#include "merge-sort.h"
#include "memutils.h"

void msort(data_t* p_arr, size_t size) {
    mergeSort(p_arr, 0, size - 1);
}

static void mergeSort(data_t* p_arr, size_t p, size_t r) {
    size_t q;
    if ( p < r ) {
        q = (r + p) / 2;

        mergeSort(p_arr, p, q);
        mergeSort(p_arr, q + 1, r);

        merge(p_arr, p, q, r);
    }
}

// from Cormen

static void merge(data_t* p_arr, size_t start, size_t mid, size_t end) {
    data_t* L = NULL;
    data_t* R = NULL;
    
    size_t n_1 = mid - start + 1;
    size_t n_2 = end - mid;

    size_t i, j, k, cnt;

    L = (data_t*) xcalloc(n_1 + 1, sizeof(data_t));
    R = (data_t*) xcalloc(n_2 + 1, sizeof(data_t));

    for ( cnt = 0; cnt < n_1; cnt++ )
        L[cnt] = p_arr[start + cnt];

    for ( cnt = 0; cnt < n_2; cnt++ ) 
        R[cnt] = p_arr[mid + cnt + 1];

    // sentinel
    L[n_1] = INT_MAX;
    R[n_2] = INT_MAX;

    i = j = 0;
    k = start;
    while ( k <= end ) {  // k < r
        if ( L[i] <= R[j] ) {
            p_arr[k++] = L[i++];
        } else {
            p_arr[k++] = R[j++];
        }
    }

    destroy_array(&L);
    destroy_array(&R);
}

// from CPA
/*
static void merge(data_t* p_arr, size_t start, size_t mid, size_t end) {
    data_t* L = NULL;
    data_t* R = NULL;

    // 1 2 3 4 5 6 7 8 9
    // start 0
    // size = end = 9
    // mid = size/2 = 4
    // n1 = 4 - 0 + 1 = 5
    // n2 = 9 - 4 = 5
    size_t n_1 = mid - start + 1;
    size_t n_2 = end - mid;

    size_t i, j, k, cnt;

    L = (data_t*) xcalloc(n_1, sizeof(data_t));
    R = (data_t*) xcalloc(n_2, sizeof(data_t));

    for ( cnt = 0; cnt < n_1; cnt++ )
        L[cnt] = p_arr[start + cnt];

    for ( cnt = 0; cnt < n_2; cnt++ )
        R[cnt] = p_arr[mid + cnt + 1];

    i = j = k = 0;
    while (TRUE) {
        if ( L[i] <= R[j] ) {
            p_arr[start + k++] = L[i++];
            
            if (i == n_1) {
                while (j < n_2) {
                    p_arr[start + k++] = R[j++];
                }

                break;
            }
        } else {
            p_arr[start + k++] = R[j++];

            if (j == n_2) {
                while (i < n_1) {
                    p_arr[start + k++] = L[i++];
                }
                
                break;
            }
        }
    }

    destroy_array(&L);
    destroy_array(&R);
}
*/
