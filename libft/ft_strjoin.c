#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{   
    size_t i;
    size_t j;
    char *s3;

    if(!s1 || !s2)
        return(NULL);
    s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
    if(!s3)
        return(NULL);
    
    i = 0;
    while(s1[i] != '\0')
    {
        s3[i] = s1[i];
        i++;
    }
    j = 0;
    while(s2[j] != '\0')
    {
        s3[i] = s2[j];
        i++;
        j++;
        
    }
    s3[i] = '\0';
    return(s3);

}