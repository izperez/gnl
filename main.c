/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:53:02 by izperez           #+#    #+#             */
/*   Updated: 2023/11/23 17:57:45 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int i;

	if (argc < 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	i = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Linea %d: %s", i, line);
		free(line);
		i++;
	}
	printf("\n");
	close(fd);
	return (0);
}
