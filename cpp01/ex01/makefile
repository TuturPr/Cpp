# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariou <ariou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/09/22 12:35:07 by ariou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = horde

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
