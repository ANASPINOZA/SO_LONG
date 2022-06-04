#include "so_long.h"

// # define WINDOW_WIDTH 600
// # define WINDOW_HIGHT 300

int main(int ac, char **av)
{
	void	*mlx_ptr;
	void	*window_ptr;
	void 	*image_ptr;
	int		i = 64;
	int		p;
	
	p = parse_map(ac, &av[1]);
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, 800, 500, "ANASPINOZA TV");
	image_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/MARIO2.xpm", &i, &i);
	mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, 64, 64);
	image_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/player.xpm", &i, &i);
	mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, 0, 0);
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, window_ptr);
}
