/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:53:02 by izperez           #+#    #+#             */
/*   Updated: 2023/11/21 11:26:31 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("prueba1.txt", O_RDONLY);
	line = "algo";
	while (line)
	{
		line = get_next_line(fd);
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
