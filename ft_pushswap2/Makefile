NAME = push_swap

SRCS =	commonfunction.c main.c add_value.c algo.c\
		deplacement.c push.c \
		rotate.c rrotate.c stackmanagement.c \
		swap.c tri3.c checkargv.c

OBJS = ${SRCS:.c=.o}
SRCS_BONUS = checker/checker.c commonfunction.c main.c add_value.c algo.c\
		deplacement.c push.c \
		rotate.c rrotate.c stackmanagement.c \
		swap.c tri3.c checkargv.c
INCS = ft_sort.h
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : ${NAME}

${NAME} :
	${CC} ${CFLAGS} $(SRCS) -o $(NAME)
	
bonus :
	${CC} ${CFLAGS} $(SRCS_BONUS) -o $(NAME)
.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all