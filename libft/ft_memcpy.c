#include "libft.h"

void *ft_memcpy(void *dest, const void *src, size_t n)
{
    size_t i;
    unsigned char *destiny;
    unsigned char *source;

    destiny = (unsigned char *)dest;
    source = (unsigned char *)src;
    i = 0;
    while(i < n)
    {
        destiny[i] = source[i];
        i++;
    }
    return(dest);


}