CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCDIR_PUSH_SWAP = src/push_swap
SRCDIR_CHECKER = src/checker
INCDIR = includes

SRC_PUSH_SWAP = $(SRCDIR_PUSH_SWAP)/check_args.c $(SRCDIR_PUSH_SWAP)/cost.c $(SRCDIR_PUSH_SWAP)/do_moves.c \
                $(SRCDIR_PUSH_SWAP)/fill_stack.c $(SRCDIR_PUSH_SWAP)/ft_atoi.c $(SRCDIR_PUSH_SWAP)/ft_putendl_fd.c \
                $(SRCDIR_PUSH_SWAP)/main.c $(SRCDIR_PUSH_SWAP)/position.c $(SRCDIR_PUSH_SWAP)/push.c \
                $(SRCDIR_PUSH_SWAP)/reverse_rotate.c $(SRCDIR_PUSH_SWAP)/rotate.c $(SRCDIR_PUSH_SWAP)/sort_three.c \
                $(SRCDIR_PUSH_SWAP)/sort.c $(SRCDIR_PUSH_SWAP)/stack_utils.c $(SRCDIR_PUSH_SWAP)/stack_utils2.c \
                $(SRCDIR_PUSH_SWAP)/swap.c $(SRCDIR_PUSH_SWAP)/ft_split.c $(SRCDIR_PUSH_SWAP)/string_utils.c

SRC_CHECKER = $(SRCDIR_CHECKER)/check_args.c $(SRCDIR_CHECKER)/do_moves.c $(SRCDIR_CHECKER)/ft_atoi.c $(SRCDIR_CHECKER)/ft_putendl_fd.c \
				$(SRCDIR_CHECKER)/main.c $(SRCDIR_CHECKER)/push.c $(SRCDIR_CHECKER)/reverse_rotate.c \
				$(SRCDIR_CHECKER)/rotate.c $(SRCDIR_CHECKER)/stack_utils.c $(SRCDIR_CHECKER)/stack_utils2.c $(SRCDIR_CHECKER)/swap.c \
				$(SRCDIR_CHECKER)/string_utils.c $(SRCDIR_CHECKER)/get_next_line_utils.c \
				$(SRCDIR_CHECKER)/get_next_line.c $(SRCDIR_CHECKER)/ft_split.c

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

NAME_PUSH_SWAP = push_swap
NAME_CHECKER = checker

all: $(NAME_PUSH_SWAP)

$(NAME_PUSH_SWAP): $(OBJ_PUSH_SWAP)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME_PUSH_SWAP) $(OBJ_PUSH_SWAP)

bonus: $(NAME_CHECKER)

$(NAME_CHECKER): $(OBJ_CHECKER)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $(NAME_CHECKER) $(OBJ_CHECKER)

clean:
	$(RM) $(OBJ_PUSH_SWAP) $(OBJ_CHECKER)

fclean: clean
	$(RM) $(NAME_PUSH_SWAP) $(NAME_CHECKER)

re: fclean all

$(SRCDIR_PUSH_SWAP)/%.o: $(SRCDIR_PUSH_SWAP)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(SRCDIR_CHECKER)/%.o: $(SRCDIR_CHECKER)/%.c
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
