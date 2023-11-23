NAME = get_next_line.a

SRCS =  get_next_line.c get_next_line_utils.c

SRCS_BNS = get_next_line_bonus.c get_next_line_utils_bonus.c

INCS = includes

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_BNS = $(SRCS_BNS:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME)

.c.o :
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I includes

$(NAME): $(OBJS)
		ar -rc $(NAME) $(OBJS)

bonus : $(OBJS_BNS)
		ar -rc $(NAME) $(OBJS_BNS)

clean:
		rm -f $(OBJS)
		rm -f $(OBJS_BNS)

fclean: clean
		rm -f $(NAME)

re: fclean all
