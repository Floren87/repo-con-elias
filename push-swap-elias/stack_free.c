#include "push_swap.h"

void	stack_free(t_node **stack)
{
	t_node	*current;
	t_node	*next;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	stacks_free(t_stacks *s)
{
	if (!s)
		return ;
	stack_free(&s->a);
	stack_free(&s->b);
	free(s);
}
