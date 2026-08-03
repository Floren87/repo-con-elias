#include "push_swap.h"

static void	reverse_rotate(t_node **stack)
{
	t_node	*last;
	t_node	*prev;

	last = *stack;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	op_rra(t_stacks *s)
{
	if (s->size_a < 2)
		return ;
	reverse_rotate(&s->a);
	write(1, "rra\n", 4);
	s->op_counts[OP_RRA]++;
}

void	op_rrb(t_stacks *s)
{
	if (s->size_b < 2)
		return ;
	reverse_rotate(&s->b);
	write(1, "rrb\n", 4);
	s->op_counts[OP_RRB]++;
}

void	op_rrr(t_stacks *s)
{
	if (s->size_a >= 2)
		reverse_rotate(&s->a);
	if (s->size_b >= 2)
		reverse_rotate(&s->b);
	write(1, "rrr\n", 4);
	s->op_counts[OP_RRR]++;
}
