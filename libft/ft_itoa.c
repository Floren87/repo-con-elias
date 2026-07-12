#include "libft.h"

static int count_digits(long n)
{
    int count;

    count =  0;
    if(n <= 0)
        count = 1;
    while(n != 0)
    {
        n = n /10;
        count++;

    }
    return(count);
    
    }

    char *ft_itoa(int n)
    {
        long number;
        int  len;
        char *str;

        number = n;
        len = count_digits(number);
        str = malloc(len +1);

        if(str == NULL)
            return(NULL);
        str[len] = '\0';
        if(number < 0)
        {
            str[0] = '-';
            number = -number;
        }
        if(number == 0)
            str[0] = '0';
        while(number > 0)
        {
            str[--len] = (number % 10) + '0';
            number = number / 10;
        }
        return(str);
    }