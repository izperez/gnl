/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:00:41 by izperez           #+#    #+#             */
/*   Updated: 2023/11/21 12:07:16 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(char *buf)
{
	int	i;

	i = 0;
	if (!buf)
		return (0);
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n' || buf[i] == 0)
			return (i);
		i++;
	}
	return (-1);
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
	old = ft_strdup((char *)*buf);
	free(*buf);
	len = found_newline(old);
	line = ft_substr(old, 0, len);
	store = ft_substr(old, len + 1, ft_strlen(old) - len);
	*buf = store;
	return (line);
}

/* read from the file and allocate memory accordingly */
char	*gn_read(int fd, char *res)
{
	char	*buf;
	int		char_read;

	char_read = 1;
	while (char_read > 0)
	{
		buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return (NULL);
		char_read = read(fd, buf, BUFFER_SIZE);
		if (char_read == -1)
		{
			free (buf);
			return (NULL);
		}
		buf[char_read] = '\0';
		res = ft_strjoin(buf, res);
		free(buf);
		if (found_newline(res) != -1)
			break ;
	}
	return (buf);
}

/* mother function */
char	*get_next_line(int fd)
{
	static char	*buf;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = gn_read(fd, buf);
	if (!buf)
		return (NULL);
	//free(buf);
	return (gn_get_line(&buf));
}
