/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 13:10:01 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/28 18:19:56 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move(int keycode, t_game *data)
{
	int x;
	int y;

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
		exit(0);
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

void	play_sound(int soundeffect)
{
	int i = fork();
	if (i == 0)
	{
		if (soundeffect == 1)
			system("afplay ./assets/CoinSound.wav");
		else if (soundeffect == 2)
			system("afplay ./assets/mamamia.wav");
		else if (soundeffect == 3)
			system("afplay ./assets/complet.wav");
		exit(0);
	}
}

void	game_check(t_game *data, int x, int y)
{
	if (data->map_chk[data->py + y][data->px + x] == 'C')
	{
		data->coin_count--;
		play_sound(1);
	}
	if (data->map_chk[data->py + y][data->px + x] == 'X')
	{
		play_sound(2);
		wait(NULL);
		ft_putstr("GAME OVER\n");
		exit(1);
	}
	else if (data->map_chk[data->py + y][data->px + x] == 'E')
	{
		if (data->coin_count == 0)
			{
				play_sound(3);
				wait(NULL);
				ft_putstr("\nWIN !!!\n");
				exit(0);
			}
	}
}

int animation(t_game *data)
{
	data->anim++;
	render(data);
	if (data->anim >= 50)
		data->anim = 0;
	return (0);
}

int main(int ac, char **av)
{
	t_game	data;

	data.move_count = 0;
	data.dead = 0;
	data.map = check_map(&data, ac, av);
	data.mlx_ptr = mlx_init();
	data.window_ptr = mlx_new_window(data.mlx_ptr,
	PIXEL * data.map_width, PIXEL * (data.map_height + 1) , "so_long");
	ft_load_images(&data);
	mlx_hook(data.window_ptr , 02, 00, move, &data);
	mlx_hook(data.window_ptr , 17, 00, destroy_notify, &data);
	mlx_loop_hook(data.mlx_ptr, &animation, &data);
	mlx_loop(data.mlx_ptr);
}
