#include "so_long.h"

// # define WINDOW_WIDTH 640
// # define WINDOW_HIGHT 300


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
	else
		return (0);
		ft_switch_img(data, x, y);
		return (0);
}

void	ft_switch_img(t_game *data, int x, int y)
{

	if (data->map[data->py + y][data->px + x] != '1' && 
	data->map[data->py + y][data->px + x] != 'E')
	{
		game_check(data, x, y);
		

	}
}

void	game_check(t_game *data, int x, int y)
{
	if (data->map[data->py + y][data->px + x] != 'C')
		data->coin_count--;
	else if (data->map[data->py + y][data->px + x] != 'E')
		{
			if (data->coin_count == 0)
				exit(0);
		}
}

int main(int ac, char **av)
{
	t_game	data;

	data.map = check_map(&data, ac, av);
	data.mlx_ptr = mlx_init();
	data.window_ptr = mlx_new_window(data.mlx_ptr,
	PIXEL * data.map_width, PIXEL * data.map_height, "so_long");
	ft_load_images(&data);
	render(&data);
	//printf("\nx : %d  y : %d\n", data.px, data.py);
	// mlx_key_hook(data.window_ptr, &move, &data);
	mlx_hook(data.window_ptr , 02, 00, move, &data);
	mlx_loop(data.mlx_ptr);
}
