#include "so_long.h"

// # define WINDOW_WIDTH 640
// # define WINDOW_HIGHT 300

int main(int ac, char **av)
{
	t_game	data;

	data.map = check_walls(&data, ac, av);
	data.mlx_ptr = mlx_init();
	data.window_ptr = mlx_new_window(data.mlx_ptr,
	PIXEL * data.map_width, PIXEL * data.map_height, "so_long");
	ft_load_images(&data);
	render(data);
	mlx_loop(data.mlx_ptr);
}

