/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 09:52:44 by izperez           #+#    #+#             */
/*   Updated: 2023/11/21 12:06:07 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	char	*alt;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	alt = malloc((1 + i) * sizeof(char) + 1);
	if (!alt)
		return (0);
	while (j < i)
	{
		alt[j] = s1[j];
		j++;
	}
	alt[i] = '\0';
	return (alt);
}

/* join 2 str*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	ptr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ptr)
		return (0);
	while (s1[i] != 0)
	{
		ptr[i + j] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		ptr[i + j] = s2[j];
		j++;
	}
	ptr[i + j] = 0;
	return (ptr);
}

/* found str in my array */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{	
	char	*sub;
	size_t	i;
	size_t	size;

	sub = 0;
	i = 0;
	if (!s)
		return (0);
	/* if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup("")); */
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	sub = (char *) malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	return (sub);
}

/* find the length */
unsigned int	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* find a char in the string */
char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (str + i);
		i++;
	}
	if ((unsigned char) c == '\0')
		return (str + i);
	else
		return (0);
}
