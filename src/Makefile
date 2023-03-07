NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c parser.c rule_rotate.c rule_switch_push.c cdlst.c algorithm.c util.c partition.c
OBJS = $(SRCS:.c=.o)

all: make_mandatory

make_mandatory: $(OBJS)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../libft -lft
	touch $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f make_mandatory
	$(MAKE) -C ../libft fclean

fclean: clean
	rm -f $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re