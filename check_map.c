/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/28 23:00:51 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(int i,int j, int map_len, t_game *data)
{
    while (data->map_chk[i - 1][j] && data->map_chk[0][j])
	{
		if (data->map_chk[i - 1][j] != '1' || data->map_chk[0][j] != '1')
			ft_error("above or bottom ");
		j++;
	}
	j = 0;
	while (data->map_chk[++j])
	{
		if (data->map_chk[j][0] != '1' || data->map_chk[j][map_len - 1] != '1')
			ft_error("righ side or left side");
	}
	i = 0;
	while (data->map_chk[++i])
	{
	j = -1;
		while (data->map_chk[i][++j])
		{
			if (data->map_chk[i][j] != 'C' && data->map_chk[i][j] != 'P' && data->map_chk[i][j] != 'E' && 
			data->map_chk[i][j] != '0' && data->map_chk[i][j] != '1' && data->map_chk[i][j] != 'X')
				ft_error("items ");
		}
	}
    i = 0;
	check_map_items(&data->map_chk[i], data);
}

int	ft_chr_count(const char *s, int c)
{
    int count;
    
    count = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
            count++;
		s++;
	}
    return (count);
}
