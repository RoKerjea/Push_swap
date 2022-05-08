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

# ================================ #
# ========== MAKE BONUS ========== #
# ================================ #

NAMEB		= checker
SRCSB		= bonus/srcs/checker.c bonus/libft/ft_split.c bonus/libft/ft_strdup.c 
SRCSB		:= $(SRCSB) bonus/srcs/parsing.c bonus/srcs/operation.c bonus/srcs/sorted.c bonus/srcs/mklst.c
SRCSB		:= $(SRCSB) bonus/libft/ft_strlen.c bonus/libft/ft_freetab.c bonus/libft/ft_strjoin.c
OBJECTSB	= ${SRCSB:.c=.o}

${NAMEB}:	${OBJECTSB} 
			${CC} ${CFLAGS} -o ${NAMEB} ${OBJECTSB}

bonus:		${NAMEB}

cleanb:
	${RM} ${OBJECTSB}

fcleanb:
	${RM} ${OBJECTSB}
	${RM} ${NAMEB}

reb:		fclean bonus

.PHONY:		all clean fclean re bonus reb