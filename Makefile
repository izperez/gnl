# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: izperez <izperez@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/19 10:55:46 by izperez           #+#    #+#              #
#    Updated: 2023/11/23 18:00:24 by izperez          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:	get_next_line

get_next_line: repo/get_next_line.c repo/get_next_line_utils.c repo/get_next_line.h main.c
		gcc -Wall -Werror -Wextra repo/get_next_line.c repo/get_next_line_utils.c main.c -Irepo/ -o get_next_line -D BUFFER_SIZE=42

clean:
	rm -f get_next_line

.PHONY: all clean