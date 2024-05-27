NAME = lib.a
SRC = create_stack.c
LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a
FLAGS = -Werror -Wall -Wextra
OBJS = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFTDIR) $(OBJS)
	@$(MAKE) -C $(LIBFTDIR)
	mv ./libft/*.o ./obj
	

$(NAME):
	cp libft/libft.a lib.a
	ar rc lib.a $(OBJS)

clean:
	rm obj/*.o

fclean: clean
	rm libft/libft.a lib.a