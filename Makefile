NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	main.c \
			ops_swap.c \
			ops_push.c \
			ops_rotate.c \
			stack_utils.c \
			parse.c \
			disorder.c \
			sort_simple.c \
			sort_medium.c \
			sort_complex.c \
			sort_adaptive.c \
			error.c

OBJS	= $(SRCS:.c=.o)

LIBFT	= libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C libft clean
	rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean all

bonus:
	make -C . NAME=checker SRCS="checker_bonus.c ops_swap.c ops_push.c ops_rotate.c stack_utils.c parse.c error.c"

.PHONY: all clean fclean re bonus
