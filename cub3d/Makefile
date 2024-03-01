NAME = cub3d
SRCS = parsing.c parsing_struct.c parsing_utils.c parsing_chars.c parsing_map.c right_side.c parsing_map2.c
OBJS = ${SRCS:.c=.o}
GNL = ./gnl/get_next_line.a
LIBFT = ./libft/libft.a
CC = cc
CFLAGS = -g3 -Wall -Wextra #-Werror
INCS = /includes

all : $(NAME) 

.c.o:
	cc $(CFLAGS) -c -o $@ $< 

$(NAME): start $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(GNL) $(LIBFT) -I $(INCS)

start :
	make -C gnl all
	make -C libft all

clean :
	${RM} ${OBJS}
	make -C gnl clean
	make -C libft clean


fclean : clean
	${RM} ${NAME}
	make -C gnl fclean
	make -C libft fclean


re : fclean all
