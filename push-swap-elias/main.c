#include "push_swap.h"

static int	is_bench_flag(char *arg)
{
	return (ft_strncmp(arg, "--bench", 8) == 0);
}

static int	get_start(int argc, char **argv, t_stacks *s)
{
	int	start;
	int	flag;

	start = 1;
	if (argc < 2)
		return (0);
	while (start < argc)
	{
		if (is_bench_flag(argv[start]))
			s->bench = 1;
		else if ((flag = parse_flag(argv[start])) != -1)
			s->strategy = flag;
		else
			break;
		start++;
	}
	if (start >= argc)
		return (0);
	return (start);
}

static void	run_strategy(t_stacks *s)
{
	if (s->strategy == SIMPLE)
	{
		s->complexity = COMPLEXITY_N2;
		sort_simple(s);
	}
	else if (s->strategy == MEDIUM)
	{
		s->complexity = COMPLEXITY_NSQRTN;
		sort_medium(s);
	}
	else if (s->strategy == COMPLEX)
	{
		s->complexity = COMPLEXITY_NLOGN;
		sort_complex(s);
	}
	else if	(s->strategy == REVERSE)
	{
		s->complexity = COMPLEXITY_N2;
		sort_reverse(s);
	}
	else
		sort_adaptive(s);
}

int	main(int argc, char **argv)
{
	t_stacks	*s;
	int			start;

	if (argc < 2)
		return (0);
	s = stacks_init();
	start = get_start(argc, argv, s);
	if (!start)
	{
		stacks_free(s);
		return (0);
	}
	parse_input(s, argc, argv, start);
	assign_ranks(s);
	s->disorder = compute_disorder(s);
	if (!is_sorted(s))
		run_strategy(s);
	if (s->bench)
		print_bench(s);
	stacks_free(s);
	return (0);
}
