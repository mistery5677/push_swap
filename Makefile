NAME = lib.a
SRC = algorithm.c algorithm_utils.c create_stack.c get_number.c moves.c moves_utils.c push_swap.c sorting_utils.c sorting.c find_bf.c options.c
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

clean:
	rm -f $(OBJDIR)/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
