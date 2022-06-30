/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:10:01 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/29 23:31:22 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (keycode == 13)
		y = -1;
	else if (keycode == 1)
		y = 1;
	else if (keycode == 0)
		x = -1;
	else if (keycode == 2)
		x = 1;
	else if (keycode == 53)
		end_game(data);
	else
		return (0);
	ft_switch_img(data, x, y);
	return (0);
}

void	ft_switch_img(t_game *data, int x, int y)
{
	if (data->map_chk[data->py + y][data->px + x] != '1' &&
	data->map_chk[data->py + y][data->px + x] != 'E')
	{
		if (x == 1)
			data->rorl = 1;
		else if (x == -1)
			data->rorl = 0;
		game_check(data, x, y);
		moves(++data->move_count);
		data->map_chk[data->py][data->px] = '0';
		data->map_chk[data->py + y][data->px + x] = 'P';
		data->px += x;
		data->py += y;
	}
	else if (data->map_chk[data->py + y][data->px + x] == 'E')
		game_check(data, x, y);
}

void	game_check(t_game *data, int x, int y)
{
	if (data->map_chk[data->py + y][data->px + x] == 'C')
		data->coin_count--;
	else if (data->map_chk[data->py + y][data->px + x] == 'E')
	{
		if (data->coin_count == 0)
		{
			ft_putstr("\nWIN !!!\n");
			end_game(data);
		}
	}
}

int	animation(t_game *data)
{
	render(data);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;

	intial_vars(&data);
	data.map_chk = check_map(&data, ac, av);
	data.mlx_ptr = mlx_init();
	data.window_ptr = mlx_new_window(data.mlx_ptr,
			PIXEL * data.map_width, PIXEL * (data.map_height), "so_long");
	ft_load_images(&data);
	mlx_hook(data.window_ptr, 02, (1L << 0), move, &data);
	mlx_hook(data.window_ptr, 17, 00, destroy_notify, &data);
	mlx_loop_hook(data.mlx_ptr, &animation, &data);
	mlx_loop(data.mlx_ptr);
}
