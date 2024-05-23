NAME = lib.a

LIBFTDIR = ./libft
LIBFT = $(LIBFTDIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT): $(LIBFTDIR)
	@$(MAKE) -C $(LIBFTDIR)
	mv ./libft/*.o ./obj

$(NAME):
	cp libft/libft.a lib.a

clean:
	rm obj/*.o

fclean: clean
	rm libft/libft.a lib.a