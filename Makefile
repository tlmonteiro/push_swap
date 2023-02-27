NAME = push_swap.a

LIB = push_swap.h

C_SOURCES = parse_utils.c lst_utils.c ft_libft.c printf_utils.c ps_moves.c push_swap.c stack_utils.c sorting_utils.c \
			moves_counter.c ps_double_moves.c

#BONUS_SOURCES =

OBJ = $(C_SOURCES:.c=.o)

#OBJ_BONUS = $(BONUS_SOURCES:.c=.o)

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