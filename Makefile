SRCS		=	srcs/push_swap.c \
				srcs/mklst.c \
				srcs/operation.c \
				srcs/algo.c \
				srcs/parsing.c \
				srcs/median.c \
				srcs/sorted.c \
				srcs/double_ope.c \
				srcs/named_ope.c \
				srcs/quicksort.c \
				srcs/push.c \
				srcs/secret_push.c \
				srcs/push_accessories.c

LIB			=	Libft/ft_atol.c \
				Libft/ft_split.c \
				Libft/ft_strdup.c \
				Libft/ft_strlen.c \
				Libft/ft_freetab.c \
				Libft/ft_strjoin.c

TOTAL = $(SRCS) $(LIB)

HEADER		= include/push_swap.h
RM			= rm -rf
NAME		= push_swap
CC			= gcc $(CFLAGS)
OBJECTS		= ${TOTAL:.c=.o}
DEPEND		= ${TOTAL:.c=.d}
CFLAGS		= -Wall -Werror -Wextra -MMD

${NAME}:	${OBJECTS}
	${CC} -o ${NAME} ${OBJECTS}

all:		${NAME}

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@

#%.d: %.c $(HEADER)
#	$(CC) -MM -MD -o $@ $<

clean:
	${RM} ${OBJECTS} ${DEPEND}

fclean:
	${RM} ${OBJECTS} ${DEPEND}
	${RM} ${NAME}

re:			fclean all

# ================================ #
# ========== MAKE BONUS ========== #
# ================================ #

NAMEB		= checker
SRCSB		= bonus/srcs/checker.c bonus/libft/ft_split.c bonus/libft/ft_strdup.c bonus/srcs/command_parsing.c
SRCSB		:= $(SRCSB) bonus/srcs/parsing.c bonus/srcs/operation.c bonus/srcs/sorted.c bonus/srcs/mklst.c
SRCSB		:= $(SRCSB) bonus/libft/ft_strlen.c bonus/libft/ft_freetab.c bonus/libft/ft_strjoin.c bonus/libft/ft_atol.c
OBJECTSB	= ${SRCSB:.c=.o}

${NAMEB}:	${OBJECTSB} 
			${CC} -o ${NAMEB} ${OBJECTSB}

bonus:		${NAMEB}

cleanb:
	${RM} ${OBJECTSB}

fcleanb:
	${RM} ${OBJECTSB}
	${RM} ${NAMEB}

reb:		fcleanb bonus

.PHONY:		all clean fclean re bonus reb