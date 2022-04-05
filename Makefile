SRCS		= srcs/push_swap.c srcs/mklst.c
LIB			= Libft/ft_atol.c Libft/ft_putnbr.c
HEADER		= include/push_swap.h
RM			= rm -rf
NAME		= push_swap
CC			= gcc
OBJECTS		= ${SRCS:.c=.o} ${LIB:.c=.o}
CFLAGS		= -Wall -Werror -Wextra 

${NAME}:	${HEADER} ${OBJECTS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJECTS}

all:		${NAME}

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:		
	${RM} ${OBJECTS}

fclean:
	${RM} ${OBJECTS}
	${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re bonus reb