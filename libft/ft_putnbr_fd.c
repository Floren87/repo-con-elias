#include <unistd.h>
#include "libft.h"

static void ft_putnbr(long nb, int fd)
{   
    char    c;

    if(nb < 0)
    {
        write(fd, "-", 1);
        nb = -nb;
    }
    if(nb >= 10)
        ft_putnbr(nb / 10, fd);
    c = (nb % 10) + '0';
    write(fd, &c, 1);
    
}

void ft_putnbr_fd(int n, int fd)
{
    ft_putnbr(n, fd);
}