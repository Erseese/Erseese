NAME = so_long
SRCS = no_bonus/initstruct.c no_bonus/movements.c no_bonus/parsing.c no_bonus/pathfinding.c no_bonus/so_long.c no_bonus/so_long_utils.c no_bonus/sprite.c
SRCS_BNS = bonus/sprite_bonus.c bonus/so_long_utils_bonus.c bonus/so_long_bonus.c bonus/parsing_bonus.c bonus/pathfinding_bonus.c bonus/movements_bonus.c bonus/initstruct_bonus.c
OBJS_BNS = ${SRCS_BNS:.c=.o}
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I/usr/include -Imlx
MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
LIB = ./test2/get_next_line.a
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
CC = cc



all : $(NAME) 

.c.o:
	cc $(CFLAGS) -c -o $@ $< $(INCLUDES)
 
#$(NAME): start $(OBJS)
#	cc $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIB)
bonus : start
	$(CC) $(CFLAGS) $(SRCS_BNS) -o $(NAME) $(MLX_FLAGS) $(INCLUDES) $(LIB) $(PRINTF) $(LIBFT)

$(NAME): start
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME) $(MLX_FLAGS) $(INCLUDES) $(LIB) $(PRINTF) $(LIBFT)

start :
	make -C printf all
	make -C test2 all
	make -C libft all

clean :
	${RM} ${OBJS}
	make -C printf clean
	make -C test2 clean
	make -C libft clean


fclean : clean
	${RM} ${NAME}
	make -C printf fclean
	make -C test2 fclean
	make -C libft fclean


re : fclean all
