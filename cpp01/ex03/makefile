# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ariou <ariou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/04 17:23:35 by arthur            #+#    #+#              #
#    Updated: 2025/09/22 11:58:37 by ariou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = brainz

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

# Sources

SRC = main.cpp\
	  HumanA.cpp\
	  HumanB.cpp\
	  Weapon.cpp

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
