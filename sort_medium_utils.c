#include "push_swap.h"

static int	isqrt(int n)
{
	int	i;

	i = 1;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	dist_to_top(int pos, int size)
{
	if (pos > size - pos)
		return (size - pos);
	return (pos);
}

int	closest_in_chunk(t_stacks *s, int chunk_limit)
{
	t_node	*node;
	int		pos;
	int		best;
	int		best_dist;

	node = s->a;
	pos = 0;
	best = 0;
	best_dist = s->size_a;
	while (node)
	{
		if (node->rank <= chunk_limit
			&& dist_to_top(pos, s->size_a) < best_dist)
		{
			best_dist = dist_to_top(pos, s->size_a);
			best = pos;
		}
		pos++;
		node = node->next;
	}
	return (best);
}

void	rotate_a_to_top(t_stacks *s, int pos)
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

int	chunk_size_for(int n)
{
	return (isqrt(n));
}
