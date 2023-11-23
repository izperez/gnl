/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 10:52:51 by izperez           #+#    #+#             */
/*   Updated: 2023/11/23 17:47:18 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	gn_strlen(char *str);
char	*gn_strncpy(char *dest, const char *src, size_t n);
char	gn_strchr(char *str, char c);
void	gn_free(void *ptr);

char	*get_next_line(int fd);

#endif