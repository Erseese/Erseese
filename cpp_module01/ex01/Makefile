NAME = Zombie
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Zombie.cpp zombieHorde.cpp newZombie.cpp main.cpp
OBJS = ${SRCS:.cpp=.o}
INCLUDES = .

all : ${NAME}

.cpp.o :
	${CC} $(FLAGS) -c -o $@ $< $(INCLUDES)

${NAME} :
	${CC} ${FLAGS} ${SRCS} -o ${NAME} -I $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

