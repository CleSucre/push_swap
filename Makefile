ifeq ($(OS), Windows_NT)
	DIRSEP	= \\
	CP		= copy
	RM		= del -f
else
	DIRSEP	= /
	CP		= cp
	RM		= rm -f
endif

NAME		= push_swap

SRCS		= src${DIRSEP}main.c src${DIRSEP}push_swap.c src${DIRSEP}moves.c \
		src${DIRSEP}parsing.c src${DIRSEP}swap.c src${DIRSEP}shift.c src${DIRSEP}push.c

OBJ_PATH	= obj${DIRSEP}

OBJ_NAME	= ${SRCS:%.c=%.o}

OBJS		= ${addprefix ${OBJ_PATH}, ${OBJ_NAME}}

CC			= gcc

HEAD		= include

LIBFT_DIR	= libft

CFLAGS		= -g -I ${HEAD}

${OBJ_PATH}%.o : %.c
	mkdir -p ${@D} 2> ${DIRSEP}dev${DIRSEP}null || true
	${CC} ${CFLAGS} -o $@ -c $<

${NAME}: ${OBJS}
	make -C ${LIBFT_DIR}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${LIBFT_DIR} -lft

all: ${NAME}
	make -C ${LIBFT_DIR} all
	${CC} ${CFLAGS} -o ${NAME} ${OBJS} -L ${LIBFT_DIR} -lft

clean:
	make -C ${LIBFT_DIR} clean
	${RM} -r ${OBJ_PATH} 2> ${DIRSEP}dev${DIRSEP}null || true

fclean:
	make -C ${LIBFT_DIR} fclean
	${RM} -r ${OBJ_PATH} 2> ${DIRSEP}dev${DIRSEP}null || true
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
