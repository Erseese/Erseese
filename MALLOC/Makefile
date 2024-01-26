LIBNAME = libft_malloc
HOSTTYPE ?= $(shell uname -m)_$(shell uname -s)
LIB = $(LIBNAME)_$(HOSTTYPE).so
LINK = $(LIBNAME).so
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(LINK)
# Création de la bibliothèque dynamique
$(LIB): $(OBJ)
	$(CC) -shared -o $@ $^

# Création du lien symbolique
$(LINK): $(LIB)
	ln -sf $< $@

%.o: %.c
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB) $(LINK)

re: fclean all

.PHONY: all clean fclean re
