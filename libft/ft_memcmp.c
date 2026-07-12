#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    const unsigned char *str1;
    const unsigned char *str2;
    size_t i;

    i = 0;
    str1 = s1;
    str2 = s2;
    if(n == 0)
        return(0);
    while(i < n)
    {
        if(str1[i] != str2[i])
            return(str1[i] - str2[i]);
        i++;
    }
    return(0);
}