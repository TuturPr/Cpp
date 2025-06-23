# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperceva <aperceva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/06/21 16:46:00 by aperceva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = brainz

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Sources

SRC = main.cpp \
	  zombieHorde.cpp \
	  Zombie.cpp

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
