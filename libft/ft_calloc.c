#include "libft.h"
#include <stdint.h>

void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;

    if(size != 0 && nmemb > SIZE_MAX / size)
        return(NULL); 
    ptr = malloc(nmemb * size);
    if(ptr == NULL)
        return(NULL);
    ft_bzero(ptr, nmemb * size);
    return(ptr);
}