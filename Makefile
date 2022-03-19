NAME1 = push_swap
NAME2 = checker
LH = push_swap.h
SRCS = operations_pa_pb.c operations_ra_rra_rb_rrb.c operations_sa_sb.c \
	order.c stack.c small_sort.c sort.c receive_args.c push_swap.c
SRCS_B = operations_pa_pb.c operations_ra_rra_rb_rrb.c operations_sa_sb.c \
	order.c stack.c bonus_utils1.c bonus_utils2.c receive_args.c checker.c
OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)
GCC = gcc
CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(GCC) $(CFLAGS) -I $(LH) -c $< -o ${<:.c=.o}
all: $(NAME1) $(NAME2)

$(NAME1): $(OBJS) $(LH)
	gcc -g $(OBJS) -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_B)

fclean: clean
	rm -f $(NAME1)
	rm -f $(NAME2)

re: fclean all

$(NAME2): $(OBJS_B) $(LH)
	gcc -g $(OBJS_B) -o $@

.PHONY: all clean fclean re
