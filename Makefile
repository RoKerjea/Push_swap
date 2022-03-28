SRCS		= srcs/push_swap.c
#LIB			= pipelib/ft_strjoin.c pipelib/ft_strlen.c pipelib/ft_substr.c pipelib/ft_freetab.c
#LIB			:= $(LIB) pipelib/ft_strchr_replace.c pipelib/ft_split.c pipelib/ft_strchr.c pipelib/ft_printnbr.c
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