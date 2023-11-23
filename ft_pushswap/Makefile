SRCS =	commonfunction.c main.c add_value.c algo.c\
		deplacement.c push.c \
		rotate.c rrotate.c stackmanagement.c \
		swap.c tri3.c checkargv.c

OBJS = ${SRCS:.c=.o}
INCS = ft_sort.h
NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} $(SRCS) -o $(NAME)
	

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all