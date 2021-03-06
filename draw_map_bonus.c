/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 14:17:47 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/30 14:18:19 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_images(t_game *data)
{
	t_images	*images;
	int			wd[2];

	images = &data->images;
	images->wall_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/wall.xpm", &wd[0], &wd[1]);
	images->flag_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/flag.xpm", &wd[0], &wd[1]);
	images->coin_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/coin.xpm", &wd[0], &wd[1]);
	images->coin_img2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/coin2.xpm", &wd[0], &wd[1]);
	images->ground_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/background.xpm", &wd[0], &wd[1]);
	images->player_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/player.xpm", &wd[0], &wd[1]);
	images->player_img2 = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/player2.xpm", &wd[0], &wd[1]);
	images->x_img = mlx_xpm_file_to_image(data->mlx_ptr, \
	"./assets_bonus/plant.xpm", &wd[0], &wd[1]);
}

static void	ft_put_image_helper(t_game *data, char c, int x, int y)
{
	if (c == 'C')
	{
		if (data->anim < 25)
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
				data->images.coin_img, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
				data->images.coin_img2, x * 64, y * 64);
	}
	else if (c == 'E')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->images.flag_img, x * 64, y * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->images.x_img, x * 64, y * 64);
}

static void	ft_put_image(t_game *data, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->images.wall_img, x * 64, y * 64);
	else if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
			data->images.ground_img, x * 64, y * 64);
	else if (c == 'P')
	{
		if (data->rorl == 1)
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
				data->images.player_img, x * 64, y * 64);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->window_ptr,
				data->images.player_img2, x * 64, y * 64);
			data->px = x;
			data->py = y;
	}
	else
		ft_put_image_helper(data, c, x, y);
}

void	render(t_game *data)
{
	int	i;
	int	j;

	i = 0;
	mlx_clear_window(data->mlx_ptr, data->window_ptr);
	mlx_string_put(data->mlx_ptr, data->window_ptr, \
	(PIXEL * data->map_width) / 2.50,
		PIXEL * (data->map_height + 0.30), 0x0000FF00, "moves :");
	mlx_string_put(data->mlx_ptr, data->window_ptr, \
		(PIXEL * data->map_width) / 2.25,
		PIXEL * (data->map_height + 0.30), 0x0000FF00, \
		display_moves(data->move_count, data));
	free(data->c);
	while (data->map_chk[i])
	{
		j = 0;
		while (data->map_chk[i][j])
		{
			ft_put_image(data, data->map_chk[i][j], j, i);
			j++;
		}
		i++;
	}
}
