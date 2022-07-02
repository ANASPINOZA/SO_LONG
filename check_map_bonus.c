/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:50:51 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/30 20:48:37 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(int i, int j, int map_len, t_game *data)
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
			ft_error("righ side or left side ");
	}
	i = 0;
	item_existence(data, i, j);
	check_map_items(&data->map_chk[0], data);
}

int	ft_chr_count(const char *s, int c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
			count++;
		s++;
	}
	return (count);
}
