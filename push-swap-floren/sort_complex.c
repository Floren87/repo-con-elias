#include "push_swap.h"

static int	get_max_bits(int n)
{
	int	bits;

	bits = 0;
	while ((1 << bits) <= n - 1)
		bits++;
	return (bits);
}

static void	radix_pass(t_stacks *s, int bit)
{
	int	i;
	int	size;

	size = s->size_a;
	i = 0;
	while (i < size)
	{
		if (((s->a->rank - 1) >> bit) & 1)
			op_ra(s);
		else
			op_pb(s);
		i++;
	}
	while (s->size_b > 0)
		op_pa(s);
}

void	sort_complex(t_stacks *s)
{
	int	bits;
	int	bit;

	if (s->size_a <= 1 || is_sorted(s))
		return ;
	bits = get_max_bits(s->size_a);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(s, bit);
		bit++;
	}
}
