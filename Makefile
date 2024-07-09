
NAME = push_swap
BONUS_NAME = checker
CC = cc
FLAGS = -Wall -Werror -Wextra -g
LIBC = ar rcs
LIBFT = $(LIBFTDIR)/libft.a
LIBFTDIR =./libft
RM = rm -f

SRCS = 	algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c push_swap.c sorting_utils.c sorting.c
BONUS_SRCS = algorithm.c check.c create_stack.c find_bf_utils.c find_bf.c get_number.c moves_utils.c moves.c options.c sorting_utils.c sorting.c bonus_checker.c
			
OBJDIR = ./obj
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SRCS:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME) 
	@echo $(NAME) compiled

$(LIBFT):
	@echo libft compiling...
	@$(MAKE) -C $(LIBFTDIR) --no-print-directory
	@echo libft compiled

bonus: $(BONUS_NAME) 

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS)
	@$(CC) $(FLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS_NAME)
	@echo $(BONUS_NAME) compiled

clean:
	@$(MAKE) clean -C $(LIBFTDIR) --no-print-directory
	@$(RM) $(OBJS) $(BONUS_OBJS)
	

fclean:	clean
	@$(MAKE) fclean -C $(LIBFTDIR) --no-print-directory
	@$(RM) $(NAME) $(BONUS_NAME)

re:	fclean all

.PHONY:		all clean fclean re bonus
