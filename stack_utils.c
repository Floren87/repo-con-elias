#include "push_swap.h"

t_stacks	*stacks_init(void)
{
	t_stacks	*s;

	s = ft_calloc(1, sizeof(t_stacks));
	if (!s)
		error_exit(NULL);
	return (s);
}

t_node	*node_new(int value)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	return (node);
}

void	stack_push(t_node **stack, t_node *node)
{
	node->next = *stack;
	*stack = node;
}

t_node	*stack_pop(t_node **stack)
{
	t_node	*node;

	if (!*stack)
		return (NULL);
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	return (node);
}

int	stack_size(t_node *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

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
