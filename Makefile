NAME	= push_swap
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I.

SRCS	=	main.c \
			ops_swap.c \
			ops_push.c \
			ops_rotate.c \
			ops_rr.c \
			stack_utils.c \
			stack_free.c \
			parse.c \
			error.c \
			sort_simple.c \
			sort_medium.c \
			sort_medium_utils.c \
			sort_complex.c \
			sort_adaptive.c \
			sort_utils.c \
			disorder.c
OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

BONUS_SRCS	=	checker_bonus.c \
				checker_ops_bonus.c \
				stack_utils.c \
				stack_free.c \
				parse.c \
				sort_utils.c \
				error.c

BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

clean:
	make -C libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) checker

re: fclean all

bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o checker

.PHONY: all clean fclean re bonus
