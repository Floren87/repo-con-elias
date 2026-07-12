#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

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

void	op_ra(t_stacks *s)
{
	if (s->size_a < 2)
		return ;
	rotate(&s->a);
	write(1, "ra\n", 3);
	s->op_counts[OP_RA]++;
}

void	op_rb(t_stacks *s)
{
	if (s->size_b < 2)
		return ;
	rotate(&s->b);
	write(1, "rb\n", 3);
	s->op_counts[OP_RB]++;
}

void	op_rr(t_stacks *s)
{
	if (s->size_a >= 2)
		rotate(&s->a);
	if (s->size_b >= 2)
		rotate(&s->b);
	write(1, "rr\n", 3);
	s->op_counts[OP_RR]++;
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
