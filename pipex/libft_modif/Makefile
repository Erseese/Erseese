NAME = libft.a

SRCS =	ft_strlen.c ft_strjoin.c ft_split.c ft_strncmp.c ft_substr.c

OBJS = ${SRCS:.c=.o}
INCS = includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all