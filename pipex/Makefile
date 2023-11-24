NAME = pipex
CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
SRCS = pipex.c \
		pipex_utils.c
LIBFT = libft_modif/libft.a
PRINTF = ft_printf/libftprintf.a

all : ${NAME}

start :
	make all -C libft_modif
	make all -C ft_printf

${NAME} : start
	$(CC) $(FLAGS) $(SRCS) $(LIBFT) $(PRINTF) -o $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C ft_printf
	make fclean -C libft_modif

clean :
	$(RM) $(NAME)
	make clean -C ft_printf
	make clean -C libft_modif

re : fclean all