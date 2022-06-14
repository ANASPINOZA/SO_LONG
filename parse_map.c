/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:37:24 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/14 22:17:02 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_items(char **map)
{
	int found;
	int i;
	
	i = 1;
	found = 0;
	while (map[i])
	{
		found += (ft_strchr(map[i], 'C') != NULL);
		i++;
	}
	if (!found)
		ft_error("collectable ");
	i = 1;
	found = 0;
	while (map[i])
	{
		found += (ft_strchr(map[i], 'E') != NULL);
		i++;
	}
	if (!found)
		ft_error("EXIT ");
	i = 1;
	found = 0;
	while (map[i])
	{
		found += (ft_strchr(map[i], 'P') != NULL);
		i++;
	}
	if (!found || found > 1)
		ft_error("PLAYER  ");
}

void	ft_error(char *status)
{
	ft_putstr(status);
	write(1, "error!\n", 7);
	exit (0);
}

int map_read_check(int ac, char **av)
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
	
	fd = map_read_check (ac, av);
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

void check_walls(int ac, char **av)
{
	int		i;
	int		j;
	char	*one;
	char	**map;
	int		map_len;

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
	while (map[i - 1][j++] && map[0][j])
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			ft_error("up and down ");
	}
	j = 0;
	while (map[++j])
	{
		if (map[j][0] != '1' || map[j][map_len - 1] != '1')
			ft_error("righ and left ");
	}
	i = 0;
	while (map[++i])
	{
	j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1')
				ft_error("items ");
		}
	}
	check_map_items(&map[i = 0]);
	printf("[%d]\n", i);
}
// int main (int ac , char **av)
// {
// 	int i;
// 	int j;
// 	int	map_len;
// 	// int	found;
// 	char *one;
// 	char **map;

// 	i = 0;
// 	j = 0;
// 	one = get_map(ac, av);
// 	if (one[ft_strlen(one) - 1] == '\n')
// 		ft_error("map 4");
// 	map = ft_split(one, '\n');
// 	map_len = ft_strlen(map[i++]);
// 	while (map[i])
// 	{
// 		if (map_len != ft_strlen(map[i]))
// 			ft_error("map not rectangle ");
// 		i++;
// 	}
// 	while (map[i - 1][j] && map[0][j])
// 	{
// 		if (map[i - 1][j] != '1' || map[0][j] != '1')
// 			ft_error("up and down ");
// 		j++;
// 	}
// 	j = 1;
// 	while (map[j])
// 	{
// 		if (map[j][0] != '1' || map[j][map_len - 1] != '1')
// 			ft_error("righ and left ");
// 		j++;
// 	}
// 	i = 1;
// 	while (map[i])
// 	{
// 	j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1')
// 				ft_error("items ");
// 			j++;
// 		}
// 		i++;
// 	}
// 	i = 0;
// 	check_map_items(&map[i]);
	// i = 1;
	// found = 0;
	// while (map[i])
	// {
	// 	found += (ft_strchr(map[i], 'C') != NULL);
	// 	i++;
	// }
	// if (!found)
	// 	ft_error("collectable ");
	// i = 1;
	// found = 0;
	// while (map[i])
	// {
	// 	found += (ft_strchr(map[i], 'E') != NULL);
	// 	i++;
	// }
	// if (!found)
	// 	ft_error("EXIT ");
	// i = 1;
	// found = 0;
	// while (map[i])
	// {
	// 	found += (ft_strchr(map[i], 'P') != NULL);
	// 	i++;
	// }
	// if (!found)
	// 	ft_error("PLAYER  ");	
	
	// {
	// 	if (ft_strchr(map[i], 'C') != NULL)
	// 	{
	// 	i++;
	// 	printf("there is a collectable\n");
	// 	}
	// 	else if (ft_strchr(map[i], 'C') == NULL)
	// 	{
	// 	i++;
	// 	if (map[i] == NULL)
	// 	ft_error("collectable ");
	// 	}
	// }
// 	return (0);
// }

// Adding some comment.