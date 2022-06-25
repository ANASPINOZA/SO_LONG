#include "so_long.h"

// # define WINDOW_WIDTH 640
// # define WINDOW_HIGHT 300


int move(int keypress, t_game *data)
{
	// (void)keypress;
	if (keypress == 87)
		mlx_destroy_window(data->image_ptr, data->image_ptr);
	return (0);
}

int main(int ac, char **av)
{
	t_game	data;

	data.map = check_walls(&data, ac, av);
	data.mlx_ptr = mlx_init();
	data.window_ptr = mlx_new_window(data.mlx_ptr,
	PIXEL * data.map_width, PIXEL * data.map_height, "so_long");
	ft_load_images(&data);
	render(&data);
	//printf("\nx : %d  y : %d\n", data.px, data.py);
	// mlx_key_hook(data.window_ptr, &move, &data);
	mlx_hook(data.window_ptr , 02, 1L<<0, move, &data);
	mlx_loop(data.mlx_ptr);
}
