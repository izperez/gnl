/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:41 by izperez           #+#    #+#             */
/*   Updated: 2023/11/23 12:33:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (buf[i] == '\n' || buf[i] == 0)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

/* get the line to be shown */
char	*gn_get_line(char **buf)
{
	char	*line;
	char	*old;
	char	*store;
	int		len;

	if (!buf)
		return (NULL);
	old = *buf;
	len = found_newline(old);
	line = ft_substr(old, 0, len);
	store = ft_substr(old, len + 1, ft_strlen(old) - len);
	*buf = store;
	free(old);
	return (line);
}

/* read from the file and allocate memory accordingly */
char	*gn_read(int fd, char *line)
{
	char	*buffer;
	int		char_read;

	char_read = 1;
	while (char_read > 0)
	{
		buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buffer)
			return (NULL);
		char_read = read(fd, buffer, BUFFER_SIZE);
		if (!char_read)
		{
			free (buffer);
			return (NULL);
		}
		buffer[char_read] = '\0';
		if (!line)
			line = ft_strdup(buffer);
		else
		{
			line = ft_strjoin(line, buffer);
			break ;
		}
		free(buffer);
		if (!found_newline(line))
			break ;
	}
	return (line);
}

/* mother function */
char	*get_next_line(int fd)
{
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gn_read(fd, line);
	if (!line)
		return (NULL);
	if (!found_newline(line))
		return (NULL);
	return (gn_get_line(&line));
}
