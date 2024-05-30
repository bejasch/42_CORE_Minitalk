# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bschneid <bschneid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 15:17:16 by bschneid          #+#    #+#              #
#    Updated: 2024/05/30 12:06:45 by bschneid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = Libft_extended/libft.a
SOURCES = src/client.c src/server.c
OBJECTS = $(SOURCES:.c=.o)
FLAGS = -Wall -Werror -Wextra

all:	$(NAME)

.c.o:
	cc $(FLAGS) -c $< -o $@

$(NAME):	$(LIBFT)	$(OBJECTS)
	cc $(FLAGS) -o server src/server.o -L./Libft_extended -lft
	cc $(FLAGS) -o client src/client.o -L./Libft_extended -lft

$(LIBFT):
	$(MAKE) -C Libft_extended -f Makefile all
	$(MAKE) -C Libft_extended -f Makefile clean

clean:
	rm -f $(OBJECTS)

fclean:	clean
	rm -f Libft_extended/libft.a
	rm -f server
	rm -f client

re:	fclean all

bonus:	all

.PHONY:	all clean fclean re bonus
