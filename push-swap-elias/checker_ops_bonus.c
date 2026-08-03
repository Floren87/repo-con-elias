#include "push_swap.h"

void	c_swap(t_node **stack, int size)
{
	int	v;
	int	r;

	if (size < 2)
		return ;
	v = (*stack)->value;
	r = (*stack)->rank;
	(*stack)->value = (*stack)->next->value;
	(*stack)->rank = (*stack)->next->rank;
	(*stack)->next->value = v;
	(*stack)->next->rank = r;
}

void	c_rotate(t_node **stack, int size)
{
	t_node	*first;
	t_node	*last;

	if (size < 2)
		return ;
	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	c_rrotate(t_node **stack, int size)
{
	t_node	*last;
	t_node	*prev;

	if (size < 2)
		return ;
	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	c_push(t_node **to, t_node **from, int *to_sz, int *from_sz)
{
	t_node	*node;

	if (!*from)
		return ;
	node = *from;
	*from = (*from)->next;
	node->next = *to;
	*to = node;
	(*to_sz)++;
	(*from_sz)--;
}
