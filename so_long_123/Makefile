NAME = so_long
SRCS = no_bonus/initstruct.c no_bonus/movements.c no_bonus/parsing.c no_bonus/pathfinding.c no_bonus/so_long.c no_bonus/so_long_utils.c no_bonus/sprite.c
SRCS_BNS = bonus/sprite_bonus.c bonus/so_long_utils_bonus.c bonus/so_long_bonus.c bonus/parsing_bonus.c bonus/pathfinding_bonus.c bonus/movements_bonus.c bonus/initstruct_bonus.c
OBJS_BNS = ${SRCS_BNS:.c=.o}
OBJS = ${SRCS:.c=.o}
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lXext -lX11
LIB = ./gnl/get_next_line.a
PRINTF = ./printf/libftprintf.a
LIBFT = ./libft/libft.a
MINILIB = minilibx-linux/libmlx_Linux.a
CC = cc



all : $(NAME) 

.c.o:
	cc $(CFLAGS) -c -o $@ $< 

bonus : start $(OBJS_BNS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS_BNS) -o $(NAME) $(MINILIB) $(LIB) $(PRINTF) $(LIBFT)

$(NAME): start $(OBJS)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJS) -o $(NAME) $(MINILIB) $(LIB) $(PRINTF) $(LIBFT)

start :
	make -C minilibx-linux
	make -C printf all
	make -C gnl all
	make -C libft all

clean :
	${RM} ${OBJS}
	$(RM) ${OBJS_BNS}
	make -C printf clean
	make -C gnl clean
	make -C libft clean


fclean : clean
	${RM} ${NAME}
	make -C printf fclean
	make -C gnl fclean
	make -C libft fclean


re : fclean all
