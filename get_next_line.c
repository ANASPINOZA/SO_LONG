/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 23:26:59 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/30 00:26:28 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s)
{
	int		i;
	char	*t;

	i = 0;
	while (s[i])
		i++;
		t = (char *)malloc(i + 1);
	if (!t)
		return (NULL);
		i = 0;
	while (s[i])
	{
		t[i] = s[i];
		i++;
	}
	t[i] = 0;
	return (t);
}

char	*get_next_line(int fd)
{
	char	buff[1];
	char	line[1000000];
	int		i;
	int		n;

	if (fd < 0)
		return (NULL);
	line[0] = 0;
	i = 0;
	n = read(fd, buff, 1);
	while (n && n > 0)
	{
		line[i++] = buff[0];
		line[i] = '\0';
		if (buff[0] == '\n')
			return (ft_strdup(line));
		n = read(fd, buff, 1);
	}
	if (!line[0])
		return (NULL);
	return (ft_strdup(line));
}