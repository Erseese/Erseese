NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = ${SRCS:.c=.o}
SRCS = pipex.c pipex_utils.c pipex_utils2.c
LIBFT = libft_modif/libft.a
PRINTF = ft_printf/libftprintf.a

all : ${NAME}

start :
	make all -C libft_modif
	make all -C ft_printf

.c.o:
	cc $(CFLAGS) -c -o $@ $< 

${NAME} : start $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(PRINTF) -o $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf
	make fclean -C libft_modif

clean :
	$(RM) $(NAME)
	make clean -C ft_printf
	make clean -C libft_modif

re : fclean all