#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *new_lst;

    if(!lst || !new)
        return;
    new_lst = *lst;
    if(!*lst)
    {
        *lst = new;
        return;
    }
    while(new_lst -> next)
        new_lst = new_lst ->next;
    new_lst ->next = new;
}