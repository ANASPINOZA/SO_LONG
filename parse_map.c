/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:37:24 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/06 16:43:54 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *status)
{
	ft_putstr(status);
	write(1, "error!\n", 7);
	exit (0);
}

int map_check(int ac, char **av)
{
	int fd;
	char *test;
	
	if (ac != 2)
		ft_error("argument ");
	test = ft_strchr(av[1], '.');
	if (!test || ft_strcmp(".ber", test) != 0)
		ft_error("map 1");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("map 2");
	return (fd);
}


char *get_map (int ac, char **av)
{
	int fd;
	char *str;
	char *tmp;
	
	fd = map_check (ac, av);
	str = get_next_line(fd);
	if (!str)
		ft_error("map 3");
	tmp = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!tmp)
		ft_error("allocation ");
	while (str)
	{
		tmp = ft_strjoin(tmp, str);
		free (str);
		str = get_next_line(fd);
	}
	return (tmp);
}

int main (int ac , char **av)
{
	int i;
	int j;
	int	map_len;
	char *one;
	char **map;

	i = 0;
	j = 0;
	one = get_map(ac, av);
	if (one[ft_strlen(one) - 1] == '\n')
		ft_error("map 4");
	map = ft_split(one, '\n');
	map_len = ft_strlen(map[i++]);
	while (map[i])
	{
		if (map_len != ft_strlen(map[i]))
			ft_error("map not rectangle ");
		i++;
	}
	while (map[i - 1][j] && map[0][j])
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			ft_error("up and down ");
		j++;
	}
	j = 1;
	while (map[j])
	{
		if (map[j][0] != '1' || map[j][map_len - 1] != '1')
			ft_error("righ and left ");
		j++;
	}
	i = 1;
	while (map[i])
	{
		if (ft_strchr(map[i], 'C') != NULL)
		{
		i++;
		printf("there is a collectable\n");
		}
		else if (ft_strchr(map[i], 'C') == NULL)
		{
		i++;
		if (map[i] == NULL)
		ft_error("collectable ");
		}
	}
	

	return (0);
}

// Adding some comment.