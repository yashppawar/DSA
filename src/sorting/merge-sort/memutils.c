#include "memutils.h"

void *xcalloc(size_t nmemb, size_t size)
{
    void *ptr = NULL;

    ptr = calloc(nmemb, size);

    if ( ptr == NULL )
    {
        fprintf(stderr, "Calloc: Out of Memory\n");
        exit(EXIT_FAILURE);
    }

    return ptr;
}

void destroy_array(void** pp_array)
{
    free(*pp_array);

    *pp_array = NULL;
}

