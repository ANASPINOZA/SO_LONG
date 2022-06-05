/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:37:24 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/05 11:51:08 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int map_check(int ac, char **av)
{
	int fd;
	char *test;
	
	if (ac > 2)
	{
		write(1, "error\n", 6);
		return (0);
	}
	test = ft_strchr(av[1], '.');
	if (test != NULL)
	{
		if (ft_strncmp(".ber", test, 4) != 0)
		{
			write(1, "invalide map\n", 13);
			return (0);
		}
	}
	fd = open(av[1], O_RDWR);
	if (fd < 0)
		return (0);
	return (fd);
}

char *get_map (int ac, char **av)
{
	int fd;
	int count;
	int	size;
	char *str;
	char *tmp;
	
	// fd = map_check (ac, av);
	fd = open(av[1], O_RDWR);
	if (fd < 0)
		return (NULL);
	// printf("%d\n", fd);
	str = get_next_line(fd);
	// printf("[%s]\n", str);
	size = ft_strlen(str);
	// printf("(%d)\n", size);
	count = 0;
	tmp = malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str)
	{
		if (ft_strlen(str) == size)
		{
			count++;
			tmp = ft_strjoin(tmp, str);
			printf("(%s)\n", tmp);
		}
		free (str);
		str = get_next_line(fd);
	}
	// printf("%d", count);
	return (tmp);
}

int main (int argc , char **argv)
{
	printf("%s",get_map (argc, argv));
}