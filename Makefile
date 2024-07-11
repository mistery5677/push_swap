NAME = push_swap
BONUS = checker
SRC = algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c sorting_utils.c sorting.c
BONUS_SRC = algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c sorting_utils.c sorting.c bonus_utils.c
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
OBJDIR = ./obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o) $(OBJDIR)/push_swap.o
BONUS_OBJS = $(BONUS_SRC:%.c=$(OBJDIR)/%.o) $(OBJDIR)/bonus_checker.o
CC = gcc
FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJDIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)
	@$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

.PHONY: all clean fclean re bonus
