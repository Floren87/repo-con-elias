#include "push_swap.h"

static void	swap_top(t_node *stack)
{
	int	tmp_val;
	int	tmp_rank;

	tmp_val = stack->value;
	tmp_rank = stack->rank;
	stack->value = stack->next->value;
	stack->rank = stack->next->rank;
	stack->next->value = tmp_val;
	stack->next->rank = tmp_rank;
}

void	op_sa(t_stacks *s)
{
	if (s->size_a < 2)
		return ;
	swap_top(s->a);
	write(1, "sa\n", 3);
	s->op_counts[OP_SA]++;
}

void	op_sb(t_stacks *s)
{
	if (s->size_b < 2)
		return ;
	swap_top(s->b);
	write(1, "sb\n", 3);
	s->op_counts[OP_SB]++;
}

void	op_ss(t_stacks *s)
{
	if (s->size_a >= 2)
		swap_top(s->a);
	if (s->size_b >= 2)
		swap_top(s->b);
	write(1, "ss\n", 3);
	s->op_counts[OP_SS]++;
}
