# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 10:55:46 by izperez           #+#    #+#              #
#    Updated: 2023/11/30 11:55:56 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Werror -Wextra src/get_next_line.c src/get_next_line_utils.c main.c -Isrc/ -o get_next_line -D BUFFER_SIZE=42


bonus:
	gcc -Wall -Werror -Wextra src/get_next_line_bonus.c src/get_next_line_utils_bonus.c main_bonus.c -Isrc/ -o get_next_line -D BUFFER_SIZE=42

clean:
	rm -f get_next_line

.PHONY: all clean