SRCS		= srcs/push_swap.c srcs/mklst.c srcs/operation.c srcs/algo.c srcs/parsing.c srcs/median.c srcs/sorted.c
SRCS		:= $(SRCS) srcs/double_ope.c srcs/named_ope.c srcs/quicksort.c
SRCS		:= $(SRCS) srcs/push.c
LIB			= Libft/ft_atol.c Libft/ft_putnbr.c Libft/ft_split.c Libft/ft_strdup.c Libft/ft_strlen.c Libft/ft_freetab.c Libft/ft_strjoin.c
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