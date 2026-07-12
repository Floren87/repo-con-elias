#include "push_swap.h"

void	op_pa(t_stacks *s)
{
	t_node	*node;

	if (!s->size_b)
		return ;
	node = stack_pop(&s->b);
	stack_push(&s->a, node);
	s->size_b--;
	s->size_a++;
	write(1, "pa\n", 3);
	s->op_counts[OP_PA]++;
}

void	op_pb(t_stacks *s)
{
	t_node	*node;

	if (!s->size_a)
		return ;
	node = stack_pop(&s->a);
	stack_push(&s->b, node);
	s->size_a--;
	s->size_b++;
	write(1, "pb\n", 3);
	s->op_counts[OP_PB]++;
}
