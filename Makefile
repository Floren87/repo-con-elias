NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	=	main.c \
			ops_swap.c \
			ops_push.c \
			ops_rotate.c \
			ops_rr.c \
			stack_utils.c \
			stack_free.c \
			parse.c \
			sort_utils.c \
			disorder.c \
			sort_simple.c \
			sort_medium.c \
			sort_medium_utils.c \
			sort_complex.c \
			sort_adaptive.c \
			sort_reverse.c \
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

BONUS_OBJS	= checker_bonus.o checker_ops_bonus.o

clean:
	make -C libft clean
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make -C libft fclean
	rm -f $(NAME) checker

re: fclean all

bonus:
	make -C . NAME=checker SRCS="checker_bonus.c checker_ops_bonus.c stack_utils.c stack_free.c parse.c sort_utils.c error.c sort_reverse.o"

.PHONY: all clean fclean re bonus
