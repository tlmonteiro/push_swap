NAME = push_swap.a

LIB = push_swap.h

C_SOURCES = ft_libft.c lst_utils.c parse_utils.c printf_utils.c ps_moves.c \
			push_swap.c ps_double_moves.c stack_utils.c sort_utils.c sorting.c sort_utils_extra.c

OBJ = $(C_SOURCES:.c=.o)

CREATE = @ar -rcs

REMOVE = @rm -f

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):	$(OBJ)
			$(CREATE) $(NAME) $(OBJ) $(LIB)
			$(CC) $(CFLAGS) main.c $(NAME) -o push_swap -fsanitize=address
clean:
		$(REMOVE) *.o

fclean:	clean
		$(REMOVE) $(NAME)

re:	clean all

.PHONY: all bonus clean fclean re