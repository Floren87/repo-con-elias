#include "push_swap.h"

void	assign_ranks(t_stacks *s)
{
	t_node	*current;
	t_node	*other;
	int		rank;

	current = s->a;
	while (current)
	{
		rank = 1;
		other = s->a;
		while (other)
		{
			if (other->value < current->value)
				rank++;
			other = other->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

int	is_sorted(t_stacks *s)
{
	t_node	*node;

	node = s->a;
	while (node && node->next)
	{
		if (node->value > node->next->value)
			return (0);
		node = node->next;
	}
	return (1);
}

int	parse_flag(char *arg)
{
	if (ft_strncmp(arg, "--simple", 9) == 0)
		return (SIMPLE);
	if (ft_strncmp(arg, "--medium", 9) == 0)
		return (MEDIUM);
	if (ft_strncmp(arg, "--complex", 10) == 0)
		return (COMPLEX);
	if (ft_strncmp(arg, "--adaptive", 11) == 0)
		return (ADAPTIVE);
	if (ft_strncmp(arg, "--reverse", 10) == 0)
		return (REVERSE);
	return (-1);
}
