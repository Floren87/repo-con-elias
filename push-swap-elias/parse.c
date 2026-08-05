#include "push_swap.h"

static int	parse_digits(char *str, long *n)
{
	if (!*str)
		return (0);
	*n = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		*n = *n * 10 + (*str - '0');
		if (*n > (long)INT_MAX + 1)
			return (0);
		str++;
	}
	return (1);
}

static int	is_valid_int(char *str, long *out)
{
	int	sign;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!parse_digits(str, out))
		return (0);
	*out *= sign;
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

static void	parse_token(t_stacks *s, char *token)
{
	long	value;
	t_node	*node;

	if (!is_valid_int(token, &value))
		error_exit(s);
	if (is_duplicate(s, (int)value))
		error_exit(s);
	node = node_new((int)value);
	if (!node)
		error_exit(s);
	push_to_bottom(s, node);
}

static void	parse_str(t_stacks *s, char *str)
{
	char	token[32];
	int		i;

	while (*str)
	{
		while (*str == ' ')
			str++;
		if (!*str)
			break ;
		i = 0;
		while (*str && *str != ' ')
			token[i++] = *str++;
		token[i] = '\0';
		parse_token(s, token);
	}
}

void	parse_input(t_stacks *s, int argc, char **argv, int start)
{
	int	i;

	i = start;
	while (i < argc)
	{
		parse_str(s, argv[i]);
		i++;
	}
	if (s->size_a == 0)
		error_exit(s);
}
