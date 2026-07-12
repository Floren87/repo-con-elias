#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t i;  
    size_t s_len;
    char *new_str;

    if(!s)
        return(NULL);
    i = 0;
    s_len = ft_strlen(s);
    if(start >= s_len)
    {
        new_str = malloc(1);
        new_str[0] = '\0';
        return(new_str);
    }
    new_str = malloc(len + 1);
    if(!new_str)
        return(NULL);
    while(i < len && s[start + i] != '\0') 
    {
        new_str[i] = s[start + i];
        i++;
    }
    new_str[i] = '\0';
    return(new_str);

}