#include "push_swap.h"

void	error_exit(t_stacks *s)
{
	stacks_free(s);
	write(2, "Error\n", 6);
	exit(1);
}

void	print_bench(t_stacks *s)
{
	int	total;
	int	i;

	total = 0;
	i = 0;
	while (i < 11)
	{
		total += s->op_counts[i];
		i++;
	}
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd((int)(s->disorder * 100), 2);
	ft_putstr_fd("%\n", 2);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(s->op_counts[OP_SA], 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(s->op_counts[OP_SB], 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(s->op_counts[OP_SS], 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(s->op_counts[OP_PA], 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(s->op_counts[OP_PB], 2);
	ft_putstr_fd("\n", 2);
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RA], 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RB], 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RR], 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RRA], 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RRB], 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(s->op_counts[OP_RRR], 2);
	ft_putstr_fd("\n", 2);
}
