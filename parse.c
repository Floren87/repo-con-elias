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
	return (-1);
}

static int	is_valid_int(char *str, long *out)
{
	long	n;
	int		sign;
	int		i;

	i = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	n = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		n = n * 10 + (str[i] - '0');
		if (n > (long)INT_MAX + 1)
			return (0);
		i++;
	}
	*out = n * sign;
	if (*out > INT_MAX || *out < INT_MIN)
		return (0);
	return (1);
}

static int	is_duplicate(t_stacks *s, int value)
{
	t_node	*node;

	node = s->a;
	while (node)
	{
		if (node->value == value)
			return (1);
		node = node->next;
	}
	return (0);
}

static void	push_to_bottom(t_stacks *s, t_node *node)
{
	t_node	*last;

	s->size_a++;
	if (!s->a)
	{
		s->a = node;
		return ;
	}
	last = s->a;
	while (last->next)
		last = last->next;
	last->next = node;
}

void	parse_input(t_stacks *s, int argc, char **argv, int start)
{
	long	value;
	t_node	*node;
	int		i;

	i = start;
	while (i < argc)
	{
		if (!is_valid_int(argv[i], &value))
			error_exit(s);
		if (is_duplicate(s, (int)value))
			error_exit(s);
		node = node_new((int)value);
		if (!node)
			error_exit(s);
		push_to_bottom(s, node);
		i++;
	}
	if (s->size_a == 0)
		error_exit(s);
}
