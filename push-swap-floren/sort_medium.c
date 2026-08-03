#include "push_swap.h"

static int	find_in_b(t_stacks *s, int rank)
{
	t_node	*node;
	int		pos;

	node = s->b;
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

static void	rotate_b_to_top(t_stacks *s, int pos)
{
	int	steps;

	if (pos <= s->size_b / 2)
	{
		while (pos > 0)
		{
			op_rb(s);
			pos--;
		}
	}
	else
	{
		steps = s->size_b - pos;
		while (steps > 0)
		{
			op_rrb(s);
			steps--;
		}
	}
}

static void	pull_sorted(t_stacks *s)
{
	int	rank;

	rank = s->size_b;
	while (s->size_b > 0)
	{
		rotate_b_to_top(s, find_in_b(s, rank));
		op_pa(s);
		rank--;
	}
}

static void	push_chunks(t_stacks *s, int chunk_size)
{
	int	chunk_limit;
	int	pushed;
	int	size;

	size = s->size_a;
	chunk_limit = chunk_size;
	pushed = 0;
	while (pushed < size)
	{
		rotate_a_to_top(s, closest_in_chunk(s, chunk_limit));
		op_pb(s);
		pushed++;
		if (pushed == chunk_limit && pushed < size)
			chunk_limit += chunk_size;
	}
}

void	sort_medium(t_stacks *s)
{
	if (s->size_a <= 1 || is_sorted(s))
		return ;
	push_chunks(s, chunk_size_for(s->size_a));
	pull_sorted(s);
}
