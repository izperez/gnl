# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 10:55:46 by izperez           #+#    #+#              #
#    Updated: 2023/11/20 12:44:35 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR		= ar rcs
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
RM		= rm -f

NAME	= get_next_line.a

SRC	= get_next_line.c get_next_line_utils.c main.c
OBJ	= $(SRC:.c=.o)

%.o: %.c
		$(CC) $(CFLAGS) -c $(SRC)

all:	$(NAME)

$(NAME): $(OBJ)
		 $(AR) $(NAME) $(OBJ)

clean:	
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:		fclean all
