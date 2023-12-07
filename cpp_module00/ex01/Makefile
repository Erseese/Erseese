NAME = phonebook
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = Contact.cpp test.cpp
OBJS = ${SRCS:.cpp=.o}
INCLUDES = .

all : ${NAME}

.cpp.o :
	${CC} $(FLAGS) -c -o $@ $< $(INCLUDES)



${NAME} : $(OBJS)
	${CC} ${FLAGS} -o ${NAME} -I $(INCLUDES)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all


