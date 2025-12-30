NAME = push_swap
# SOURCES = push_swap.c command_push.c command_reverse.c command_rotate.c \
# command_swap.c helper_functions.c list_functions.c index_array.c \
# helper_functions_split.c error_handling.c sort_small_big.c build_stack.c
SOURCES = $(wildcard *.c commands/*.c helper_functions/*.c sorting/*.c)
OBJECTS = $(SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f $(NAME) a.out

re:	fclean all

.PHONY:
	all clean fclean re