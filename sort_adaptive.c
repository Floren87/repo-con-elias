#include "push_swap.h"

void	sort_adaptive(t_stacks *s)
{
	if (s->size_a <= 1 || is_sorted(s))
		return ;
	if (s->disorder < 0.2)
		sort_simple(s);
	else if (s->disorder < 0.5)
		sort_medium(s);
	else
		sort_complex(s);
}
