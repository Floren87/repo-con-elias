#include "push_swap.h"

void	sort_adaptive(t_stacks *s)
{
	if (s->size_a <= 1 || is_sorted(s))
		return ;
	if (s->disorder < 0.2)
	{
		s->complexity = COMPLEXITY_N;
		sort_simple(s);
	}
	else if (s->disorder < 0.5 && s->size_a <= 250)
	{
		s->complexity = COMPLEXITY_NSQRTN;
		sort_medium(s);
	}
	else
	{
		s->complexity = COMPLEXITY_NLOGN;
		sort_complex(s);
	}
}
