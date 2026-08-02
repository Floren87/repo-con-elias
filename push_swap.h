#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <limits.h>

/* strategy flags */
# define ADAPTIVE		0
# define SIMPLE			1
# define MEDIUM			2
# define COMPLEX		3
# define REVERSE		4

/* complexity classes for --bench output */
# define COMPLEXITY_N		0
# define COMPLEXITY_N2		1
# define COMPLEXITY_NSQRTN	2
# define COMPLEXITY_NLOGN	3

/* op indices — used by bench counters in t_stacks */
# define OP_SA		0
# define OP_SB		1
# define OP_SS		2
# define OP_PA		3
# define OP_PB		4
# define OP_RA		5
# define OP_RB		6
# define OP_RR		7
# define OP_RRA		8
# define OP_RRB		9
# define OP_RRR		10

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}	t_node;

typedef struct s_stacks
{
	t_node	*a;
	t_node	*b;
	int		size_a;
	int		size_b;
	double	disorder;
	int		strategy;
	int		complexity;
	int		bench;
	int		op_counts[11];
}	t_stacks;

/* --- operations --- */
void		op_sa(t_stacks *s);
void		op_sb(t_stacks *s);
void		op_ss(t_stacks *s);
void		op_pa(t_stacks *s);
void		op_pb(t_stacks *s);
void		op_ra(t_stacks *s);
void		op_rb(t_stacks *s);
void		op_rr(t_stacks *s);
void		op_rra(t_stacks *s);
void		op_rrb(t_stacks *s);
void		op_rrr(t_stacks *s);

/* --- stack utils --- */
t_node		*node_new(int value);
void		stack_push(t_node **stack, t_node *node);
t_node		*stack_pop(t_node **stack);
int			stack_size(t_node *stack);
void		stack_free(t_node **stack);
void		stacks_free(t_stacks *s);

/* --- parsing & validation --- */
t_stacks	*stacks_init(void);
void		parse_input(t_stacks *s, int argc, char **argv, int start);
int			parse_flag(char *arg);
void		assign_ranks(t_stacks *s);
int			is_sorted(t_stacks *s);

/* --- disorder --- */
double		compute_disorder(t_stacks *s);

/* --- algorithms --- */
void		sort_simple(t_stacks *s);
void		sort_medium(t_stacks *s);
void		sort_complex(t_stacks *s);
void    	sort_reverse(t_stacks *s);
void		sort_adaptive(t_stacks *s);
int			closest_in_chunk(t_stacks *s, int chunk_limit);
void		rotate_a_to_top(t_stacks *s, int pos);
int			chunk_size_for(int n);

/* --- error & bench --- */
void		error_exit(t_stacks *s);
void		print_bench(t_stacks *s);

/* --- checker ops (silent, no stdout) --- */
void		c_swap(t_node **stack, int size);
void		c_rotate(t_node **stack, int size);
void		c_rrotate(t_node **stack, int size);
void		c_push(t_node **to, t_node **from, int *to_sz, int *from_sz);

#endif
