#include "push_swap.h"

static int	gnl_stdin(char *buf, int max)
{
	int		i;
	char	c;
	int		ret;

	i = 0;
	ret = 1;
	while (i < max - 1 && ret > 0)
	{
		ret = read(0, &c, 1);
		if (ret <= 0 || c == '\n')
			break ;
		buf[i++] = c;
	}
	buf[i] = '\0';
	if (i == 0 && ret <= 0)
		return (-1);
	return (i);
}

static int	apply_sp(t_stacks *s, char *op)
{
	if (!ft_strncmp(op, "sa", 3))
		c_swap(&s->a, s->size_a);
	else if (!ft_strncmp(op, "sb", 3))
		c_swap(&s->b, s->size_b);
	else if (!ft_strncmp(op, "ss", 3))
	{
		c_swap(&s->a, s->size_a);
		c_swap(&s->b, s->size_b);
	}
	else if (!ft_strncmp(op, "pa", 3))
		c_push(&s->a, &s->b, &s->size_a, &s->size_b);
	else if (!ft_strncmp(op, "pb", 3))
		c_push(&s->b, &s->a, &s->size_b, &s->size_a);
	else
		return (0);
	return (1);
}

static int	apply_rot(t_stacks *s, char *op)
{
	if (!ft_strncmp(op, "rra", 4))
		c_rrotate(&s->a, s->size_a);
	else if (!ft_strncmp(op, "rrb", 4))
		c_rrotate(&s->b, s->size_b);
	else if (!ft_strncmp(op, "rrr", 4))
	{
		c_rrotate(&s->a, s->size_a);
		c_rrotate(&s->b, s->size_b);
	}
	else if (!ft_strncmp(op, "ra", 3))
		c_rotate(&s->a, s->size_a);
	else if (!ft_strncmp(op, "rb", 3))
		c_rotate(&s->b, s->size_b);
	else if (!ft_strncmp(op, "rr", 3))
	{
		c_rotate(&s->a, s->size_a);
		c_rotate(&s->b, s->size_b);
	}
	else
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;
	char		buf[16];
	int			len;

	if (argc < 2)
		return (0);
	s = stacks_init();
	parse_input(s, argc, argv, 1);
	assign_ranks(s);
	while ((len = gnl_stdin(buf, 16)) != -1)
	{
		if (len == 0)
			continue ;
		if (!apply_sp(s, buf) && !apply_rot(s, buf))
			error_exit(s);
	}
	if (is_sorted(s) && s->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stacks_free(s);
	return (0);
}
