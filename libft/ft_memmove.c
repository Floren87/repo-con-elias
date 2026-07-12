#include "libft.h"

void *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char *destiny;
    unsigned char *source;
    size_t i;

    destiny = (unsigned char *)dest;
    source = (unsigned char *)src;
    if(destiny < source)
    {   
        i = 0;
        while(i < n)
        {
            destiny[i] = source[i];
            i++;
        }
    }else
    {
        i = n;
        while(i > 0)
        {   
            i--;
            destiny[i] = source[i];     
        }
    }
    return(dest);

}