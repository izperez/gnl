/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:29:12 by izperez           #+#    #+#             */
/*   Updated: 2023/11/27 09:56:23 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

size_t	gn_strlen(char *str);
char	*gn_strncpy(char *dest, const char *src, size_t n);
char	gn_strchr(const char *str, int c);
void	gn_free(char *ptr);

char	*get_next_line(int fd);
#endif