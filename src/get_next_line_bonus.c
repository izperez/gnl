/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:55:30 by izperez           #+#    #+#             */
/*   Updated: 2023/11/28 11:16:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*gn_getline(char *line, char *buf)
{
	char	*result;
	size_t	line_len;
	size_t	buf_len;

	line_len = gn_strlen(line);
	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
		buf_len += 1;
	result = (char *)malloc(sizeof(char) * (line_len + buf_len + 1));
	if (result == NULL)
		return (gn_free(line), NULL);
	gn_strncpy(result, line, line_len);
	gn_strncpy(result + line_len, buf, buf_len);
	result[line_len + buf_len] = '\0';
	return (gn_free(line), result);
}

static void	gn_saverest(char *buf)
{
	size_t	buf_len;
	size_t	rest_len;

	buf_len = 0;
	while (buf[buf_len] != '\0' && buf[buf_len] != '\n')
		buf_len++;
	if (buf[buf_len] == '\n')
	{
		buf_len += 1;
		rest_len = gn_strlen(buf + buf_len);
		gn_strncpy(buf, buf + buf_len, rest_len);
		buf[rest_len] = '\0';
	}
	else
		buf[0] = '\0';
}

static char	*gn_readline(int fd, char *buf)
{
	char	*line;
	ssize_t	bytes_read;

	line = gn_getline(NULL, buf);
	bytes_read = 1;
	if (line == NULL)
		return (NULL);
	while (!gn_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && gn_strlen(line) == 0))
			return (buf[0] = '\0', gn_free(line), NULL);
		buf[bytes_read] = '\0';
		line = gn_getline(line, buf);
		if (line == NULL)
			return (NULL);
	}
	gn_saverest(buf);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buf[4096][BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = gn_readline(fd, buf[fd]);
	return (line);
}
