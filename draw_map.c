/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:31:48 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/23 17:05:53 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_images(t_game *data)
{
	t_images	*images;
	int			wd[2];

	images = data->images;
	images->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/wall.xpm", &wd[0], &wd[1])
	printf("wd 1 = %d, wd 2 = %d", wd[0], wd[1]);
	images->flag_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/flag.xpm", &wd[0], &wd[1])
	images->coin_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/new_coin.xpm", &wd[0], &wd[1])
	images->ground_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/background.xpm", &wd[0], &wd[1])
	images->player_img = mlx_xpm_file_to_image(data->mlx_ptr, "./assets/MARIO2.xpm", &wd[0], &wd[1])
}

static void	ft_put_image(t_game data, char c)
{
	if (c == '1')
		mlx_put_image_to_window(data.mlx_ptr, data.window_ptr,
		 data.images.wall_img, )
}

void	render(t_game data)
{
	int	i;
	int	j;

	i = 0;
	while (data.map[i])
	{
		j = 0;
		while (data.map[i][j])
		{
			ft_put_image(data, data.map[i][j]);
			j++;
		}
		i++;
	}
}