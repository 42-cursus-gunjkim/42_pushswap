NAME = push_swap
CHECKER = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./src/
BONUS_DIR = ./src_bonus/
SRCS_FILE = push_swap.c parser.c rule_rotate.c rule_switch_push.c cdlst.c sort.c util.c greedy.c push_swap_atoi.c
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILE))
BONUS_FILE = cdlst_bonus.c checker_bonus.c parser_bonus.c rule_rotate_bonus.c rule_switch_push_bonus.c util_bonus.c another_util_bonus.c
BONUS_SRCS = $(addprefix $(BONUS_DIR), $(BONUS_FILE))
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: make_mandatory
bonus: make_bonus

make_mandatory: $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L./libft -lft
	touch $@

make_bonus: $(BONUS_OBJS)
	$(MAKE) -C ./libft
	$(CC) $(CFLAGS) -o $(CHECKER) $(BONUS_OBJS) -L./libft -lft
	touch $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	rm -f make_mandatory
	rm -f make_bonus
	$(MAKE) -C ./libft fclean

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: 
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus