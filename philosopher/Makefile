NAME = philo
SRCS = checkargv.c checkatoi.c init.c main.c philo_work.c philo_utils.c control_work.c
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror -fsanitize=thread -g
INCLUDES = -I.
CC = cc

all : $(NAME) 

.c.o:
	cc $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME):
	$(CC) -g $(CFLAGS) $(SRCS) -o $(NAME) $(INCLUDES) 

clean :
	rm -f ${OBJS}

fclean : clean
	rm -f ${NAME}

re : fclean all
