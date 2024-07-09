NAME = push_swap.a
BONUS = checker.a
SRC = algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c push_swap.c sorting_utils.c sorting.c
BONUS_SRC = algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c push_swap.c sorting_utils.c sorting.c
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
OBJDIR = ./obj
OBJS = $(SRC:%.c=$(OBJDIR)/%.o)
FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)
	mv libft/*.o obj/

$(OBJDIR)/%.o: %.c | $(OBJDIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(NAME): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	cc $(FLAGS) $(NAME) -o push_swap

clean:
	rm -f $(OBJDIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

bonus: $(BONUS)

$(BONUS): $(LIBFT) $(OBJS)
	cp $(LIBFT) $(NAME)
	ar rc $(NAME) $(OBJS)
	cc $(FLAGS) $(NAME) -o checker

.PHONY: all clean fclean re
