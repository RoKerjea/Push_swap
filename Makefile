# This is a minimal set of ANSI/VT100 color codes
_END=$'\033[0m
_BOLD=$'\033[1m
_UNDER=$'\033[4m
_REV=$'\033[7m

# Colors
_GREY=$'\033[30m
_RED=$'\033[31m
_GREEN=$'\033[32m
_YELLOW=$'\033[33m
_BLUE=$'\033[34m
_PURPLE=$'\033[35m
_CYAN=$'\033[36m
_WHITE=$'\033[37m

# Inverted, i.e. colored backgrounds
_IGREY=$'\033[40m
_IRED=$'\033[41m
_IGREEN=$'\033[42m
_IYELLOW=$'\033[43m
_IBLUE=$'\033[44m
_IPURPLE=$'\033[45m
_ICYAN=$'\033[46m
_IWHITE=$'\033[47m

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

#TOTAL = $(SRCS) $(LIB)

HEADER		= include/push_swap.h
RM			= rm -rf
NAME		= push_swap
CC			= gcc $(CFLAGS)

OBJECTS_SRC	= ${SRCS:srcs/%.c=srcs/build/%.o}
DEPEND_SRC	= ${SRCS:srcs/%.c=srcs/build/%.d}
OBJECTS_LIB	= ${LIB:Libft/%.c=Libft/build/%.o}
DEPEND_LIB	= ${LIB:Libft/%.c=Libft/build/%.d}
OBJECTS		= $(OBJECTS_SRC) $(OBJECTS_LIB)
DEPEND		= $(DEPEND_SRC) $(DEPEND_LIB)
CFLAGS		= -Wall -Werror -Wextra 

${NAME}:	${OBJECTS}
	@echo "${_UNDER}${_RED}Creating Executable${_END}"
	@echo "${_BOLD}${_GREEN}${CC} -o ${NAME} ${OBJECTS}${_END}"
	@${CC} -o ${NAME} ${OBJECTS}

-include ${DEPEND}

all:	$(NAME)

srcs/build/%.o: srcs/%.c $(HEADER)
	@if [ ! -d "./srcs/build" ]; then\
		echo "${_UNDER}${_RED}Creating Objects and Dependencies${_END}";\
		echo "${_BOLD}${_UNDER}${_BLUE}"mkdir -p srcs/build"${_END}";\
		mkdir -p srcs/build;\
	fi
	@echo "${_BOLD}${_BLUE}"$(CC) -MMD -c $< -o $@"${_END}"
	@$(CC) -MMD -c $< -o $@

Libft/build/%.o: Libft/%.c $(HEADER)
	@if [ ! -d "./Libft/build" ]; then\
		echo "${_BOLD}${_UNDER}${_BLUE}"mkdir -p Libft/build"${_END}";\
		mkdir -p Libft/build;\
	fi
	@echo "${_BOLD}${_BLUE}"$(CC) -MMD -c $< -o $@"${_END}"
	@$(CC) -MMD -c $< -o $@

#%.d: %.c $(HEADER)
#	$(CC) -MM -MD -o $@ $<

clean:
	@echo "${_UNDER}${_RED}Deleting Objects and Dependencies${_END}"
	@echo "${_BOLD}${_YELLOW}"${RM} ${OBJECTS} ${DEPEND}"${_END}"
	@${RM} ${OBJECTS} ${DEPEND}
	@echo "${_BOLD}${_YELLOW}"${RM} srcs/build"${_END}"
	@${RM} srcs/build
	@echo "${_BOLD}${_YELLOW}"${RM} Libft/build"${_END}"
	@${RM} Libft/build

fclean: clean
	@echo "${_UNDER}${_RED}Deleting Executable${_END}"
	@echo "${_BOLD}${_RED}"${RM} ${NAME}"${_END}"
	@${RM} ${NAME}

gitm: fclean
	git add .
	git commit
	git push

VER_H = include/Version_pushswap.h
USER := $(shell env | grep USER | tail --bytes=+6)
TIME=$(shell date +"%d %m %Y %Hh%M %Z")

git: fclean
	$(eval MIN=$(shell expr $$(awk '/#define MINOR_VERSION/' $(VER_H) | tr -cd "[0-9]") + 1))
	$(eval MAJ=$(shell expr $$(awk '/#define MAJOR_VERSION/' $(VER_H) | tr -cd "[0-9]")))
	sed -i 's/#define MINOR_VERSION .*/#define MINOR_VERSION \"$(MIN)\"/' $(VER_H)
	sed -i 's/#define BUILD_DATE .*/#define BUILD_DATE $(TIME)/' $(VER_H)
	git add .
	git commit -m "V$(MAJ).$(MIN) by $(USER) at $(TIME)"
	git push

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