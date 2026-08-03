#include "push_swap.h"

double	compute_disorder(t_stacks *s)
{
	t_node	*outer;
	t_node	*inner;
	double	mistakes;
	double	total;

	if (s->size_a < 2)
		return (0.0);
	mistakes = 0.0;
	total = 0.0;
	outer = s->a;
	while (outer)
	{
		inner = outer->next;
		while (inner)
		{
			total++;
			if (outer->value > inner->value)
				mistakes++;
			inner = inner->next;
		}
		outer = outer->next;
	}
	return (mistakes / total);
}
