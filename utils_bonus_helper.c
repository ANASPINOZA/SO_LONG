/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus_helper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 13:33:02 by aadnane           #+#    #+#             */
/*   Updated: 2022/07/01 10:52:53 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}

int	animation(t_game *data)
{
	data->anim++;
	render(data);
	if (data->anim >= 50)
		data->anim = 0;
	return (0);
}

void	item_existence(t_game *data, int i, int j)
{
	while (data->map_chk[++i])
	{
		j = -1;
		while (data->map_chk[i][++j])
		{
			if (data->map_chk[i][j] != 'C' && data->map_chk[i][j] != 'P' \
			&& data->map_chk[i][j] != 'E' &&
		data->map_chk[i][j] != '0' && data->map_chk[i][j] != '1'
		&& data->map_chk[i][j] != 'X')
				ft_error("items ");
		}
	}
	check_map_items(&data->map_chk[0], data);
}

void	item_error(char **map, int i, int found)
{
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
