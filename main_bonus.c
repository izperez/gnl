/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:53:02 by izperez           #+#    #+#             */
/*   Updated: 2023/11/30 11:56:55 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line_bonus.h"

int	main(int argc, char **argv)
{
	int		fd1;
	int		fd2;
	char	*line;
	int		i;

	if (argc < 3)
		return (1);
	fd1 = open(argv[1], O_RDONLY);
	if (fd1 == -1)
		return (1);
	fd2 = open(argv[2], O_RDONLY);
	if (fd2 == -1)
		return (close(fd1), 1);
	i = 1;
	while (i < 10)
	{
		line = get_next_line(fd1);
		if (line != NULL)
		{
			printf("Linea fichero 1 %d: %s", i, line);
			free(line);
		}
		line = get_next_line(fd2);
		if (line != NULL)
		{
			printf("Linea fichero 2 %d: %s", i, line);
			free(line);
		}
		i++;
	}
	close(fd1);
	close(fd2);
	return (0);
}
