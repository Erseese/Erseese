SRCS =	ft_itoa.c \
		ft_print.c \
		ft_putchar.c \
		ft_printf.c
OBJS = ${SRCS:.c=.o}
INCS = .
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all