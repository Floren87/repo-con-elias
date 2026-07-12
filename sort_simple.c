#include "push_swap.h"

static int	find_rank_pos(t_stacks *s, int rank)
{
	t_node	*node;
	int		pos;

	node = s->a;
	pos = 0;
	while (node)
	{
		if (node->rank == rank)
			return (pos);
		pos++;
		node = node->next;
	}
	return (0);
}

static void	rotate_to_top(t_stacks *s, int pos)
{
	int	steps;

	if (pos <= s->size_a / 2)
	{
		while (pos > 0)
		{
			op_ra(s);
			pos--;
		}
	}
	else
	{
		steps = s->size_a - pos;
		while (steps > 0)
		{
			op_rra(s);
			steps--;
		}
	}
}

void	sort_simple(t_stacks *s)
{
	int	rank;
	int	pos;

	if (s->size_a <= 1 || is_sorted(s))
		return ;
	rank = 1;
	while (s->size_a > 0)
	{
		pos = find_rank_pos(s, rank);
		rotate_to_top(s, pos);
		op_pb(s);
		rank++;
	}
	while (s->size_b > 0)
		op_pa(s);
}
