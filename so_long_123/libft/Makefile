# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouihar <ytouihar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:58:26 by ytouihar          #+#    #+#              #
#    Updated: 2023/11/22 18:29:58 by ytouihar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_strlen.c ft_split.c ft_strchr.c ft_strrchr.c ft_strncmp.c

OBJS = ${SRCS:.c=.o}
INCS = includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : ${NAME}

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}
so:
	$(CC) -fPIC $(CFLAGS) $(SRC)
	gcc -shared -o libft.so $(OBJ)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
