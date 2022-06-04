/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:37:24 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/04 17:11:15 by aadnane          ###   ########.fr       */
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
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

char *get_map (int ac, char *av[])
{
	int fd;
	char *str;

	fd = map_check (ac, av);
	if (fd == 0)
		return (NULL);
	str = "";
	while (str)
	{
		str = get_next_line (fd);
		
		printf ("%s", str);
		free (str);
	}
	return (NULL);
}


int main (int argc , char *argv[])
{
	get_map (argc, argv);
}