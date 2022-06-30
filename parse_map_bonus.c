/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:50:04 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/29 20:06:07 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_items(char **map, t_game *data)
{
	int found;
	int i;
	
	i = 1;
	found = 0;
	while (map[i])
	{
		found += (ft_chr_count(map[i], 'C'));
		i++;
	}
	if (!found)
		ft_error("collectable ");
	data->coin_count = found;
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
		found += ft_chr_count(map[i], 'P');
		i++;
	}
	if (found != 1)
		ft_error("PLAYER  ");
    found = 0;
    i = 1;
    while (map[i])
    {
        found += (ft_strchr(map[i], 'X') != NULL);
		i++;
    }
    if (!found)
        ft_error("ENEMY ");
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
	free(str);
	return (tmp);
}

char **check_map(t_game *data ,int ac, char **av)
{
	int		i;
	int		j;
	char	*one;
	int		map_len;

	i = 0;
	j = 0;
	one = get_map(ac, av);
	if (one[ft_strlen(one) - 1] == '\n')
		ft_error("map 4");
	data->map_chk = ft_split(one, '\n');
	map_len = ft_strlen(data->map_chk[i++]);
	data->map_width = map_len;
	while (data->map_chk[i])
	{
		if (map_len != ft_strlen(data->map_chk[i]))
			ft_error("map not rectangle ");
		i++;
	}
	data->map_height = i;
	check_walls(i, j, map_len, data);
	free(one);
	return (data->map_chk);
}
