NAME = get_next_line.a

SRCS =  get_next_line.c get_next_line_utils.c

INCS = ../includes/

CC = cc

CFLAGS = -Wall -Wextra -Werror 

OBJS = $(SRCS:.c=.o)

all: $(NAME)


.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)

clean:
		rm -f $(OBJS)
		rm -f $(OBJS_BNS)

fclean: clean
		rm -f $(NAME)

re: fclean all
