#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
    unsigned char *str;
    size_t i;

    str = (unsigned char *)s;
    i = 0;
    while (i < n)
    {
        str[i] = c;
        i++;
    }
    return(s);
}