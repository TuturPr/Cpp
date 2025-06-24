# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/06/24 18:07:10 by aperceva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = animal

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Sources

SRC = main.cpp \
	  Dog.cpp \
	  Cat.cpp \
	  Animal.cpp \
	  WrongAnimal.cpp \
	  WrongCat.cpp \

OBJS = $(SRC:.cpp=.o)

# Fonctions

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
