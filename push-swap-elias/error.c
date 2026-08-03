#include "push_swap.h"

void	error_exit(t_stacks *s)
{
	stacks_free(s);
	write(2, "Error\n", 6);
	exit(1);
}

static void	print_complexity(int c)
{
	if (c == COMPLEXITY_N2)
		ft_putstr_fd("O(n^2)\n", 2);
	else if (c == COMPLEXITY_NSQRTN)
		ft_putstr_fd("O(n*sqrt(n))\n", 2);
	else if (c == COMPLEXITY_NLOGN)
		ft_putstr_fd("O(n log n)\n", 2);
	else
		ft_putstr_fd("O(n)\n", 2);
}

static void	print_bench_header(t_stacks *s)
{
	int	pct;
	int	dec;

	pct = (int)(s->disorder * 100);
	dec = (int)(s->disorder * 10000) % 100;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(pct, 2);
	ft_putstr_fd(".", 2);
	if (dec < 10)
		ft_putstr_fd("0", 2);
	ft_putnbr_fd(dec, 2);
	ft_putstr_fd("%\n[bench] strategy: ", 2);
	if (s->strategy == ADAPTIVE)
		ft_putstr_fd("Adaptive / ", 2);
	else if (s->strategy == SIMPLE)
		ft_putstr_fd("Simple / ", 2);
	else if (s->strategy == MEDIUM)
		ft_putstr_fd("Medium / ", 2);
	else
		ft_putstr_fd("Complex / ", 2);
	print_complexity(s->complexity);
}

static void	print_bench_ops(t_stacks *s)
{
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
	ft_putstr_fd("\n[bench] ra: ", 2);
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
	print_bench_header(s);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(total, 2);
	ft_putstr_fd("\n", 2);
	print_bench_ops(s);
}
