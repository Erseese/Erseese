NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Contact.cpp main.cpp Phonebook.cpp
OBJS = ${SRCS:.cpp=.o}
INCLUDES = .

all : ${NAME}

.cpp.o :
	${CC} $(FLAGS) -c -o $@ $<

${NAME} : $(OBJS)
	${CC} ${FLAGS} $(OBJS) -o ${NAME}
clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all


