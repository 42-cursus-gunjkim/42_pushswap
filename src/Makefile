NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c parser.c rule_rotate.c rule_switch_push.c cdlst.c sort.c util.c greedy.c
BONUS_SRCS = ../src_bonus/cdlst_bonus.c ../src_bonus/checker_bonus.c ../src_bonus/parser_bonus.c ../src_bonus/rule_rotate_bonus.c ../src_bonus/rule_switch_push_bonus.c ../src_bonus/util_bonus.c
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: make_mandatory
bonus: make_bonus

make_mandatory: $(OBJS)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L../libft -lft
	touch $@

make_bonus: $(BONUS_OBJS)
	$(MAKE) -C ../libft
	$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJS) -L../libft -lft
	touch $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f make_mandatory
	rm -f make_bonus
	$(MAKE) -C ../libft fclean

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus