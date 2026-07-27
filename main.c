#include "push_swap.h"

static int	is_bench_flag(char *arg)
{
	return (ft_strncmp(arg, "--bench", 8) == 0);
}

static int	get_start(int argc, char **argv, t_stacks *s)
{
	int	start;

	start = 1;
	if (argc < 2)
		return (0);
	if (is_bench_flag(argv[1]))
	{
		s->bench = 1;
		start = 2;
	}
	if (start < argc && parse_flag(argv[start]) != -1)
	{
		s->strategy = parse_flag(argv[start]);
		start++;
	}
	else if (start < argc && parse_flag(argv[start]) == -1
		&& !is_bench_flag(argv[start]))
		s->strategy = ADAPTIVE;
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
