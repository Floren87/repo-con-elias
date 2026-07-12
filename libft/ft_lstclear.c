#include "libft.h"

void    ft_lstclear(t_list **lst, void(*del)(void *))
{
    t_list *temp;
    t_list *new_lst;

    if(!lst || !del)
        return;
    new_lst = *lst;
    while(new_lst)
    {
        temp = new_lst;
        new_lst = new_lst ->next;
        ft_lstdelone(temp, del);
        
        
    }
    *lst = NULL;
}