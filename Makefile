NAME = push_swap.a
SOURCES = push_swap.c command_push.c command_revese.c command_rotate.c \
command_swap.c helper_functions.c list_functions.c parsing&validation.c \
size_of_a.c helper_functions_split.c error_handling.c
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a


all: $(NAME)

$(NAME): $(OBJECTS) 
	@make -C $(LIBFT_DIR) all
	@cp $(LIBFT) .
	ar rcs $(NAME) $(OBJECTS) $(LIBFT_DIR)/*.o


%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make -C $(LIBFT_DIR) clean
	rm -f $(OBJECTS)

fclean:	clean
	@make -C $(LIBFT_DIR) fclean
	rm -f $(NAME) a.out push_swap.a

re:	fclean all

executable: $(NAME)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT_DIR)/*.o -o a.out

.PHONY:
	all clean fclean re