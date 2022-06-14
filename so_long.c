#include "so_long.h"

// # define WINDOW_WIDTH 640
// # define WINDOW_HIGHT 300

int main(int ac, char **av)
{
	// int		i;
	// int		j;
	// int		map_len;
	void	*mlx_ptr;
	void	*window_ptr;
	// char	*one;
	// char	**map;

	// void 	*image_ptr;
	// int		i = 64;

	// int		p;
	(void)ac;
	(void)av;
	
	// p = parse_map(ac, &av[1]);
	mlx_ptr = mlx_init();
	window_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HIGHT, "ANASPINOZA TV");
	check_walls(ac, av);
	// i = 0;
	// j = 0;
	// one = get_map(ac, av);
	// if (one[ft_strlen(one) - 1] == '\n')
	// 	ft_error("map 4");
	// map = ft_split(one, '\n');
	// map_len = ft_strlen(map[i++]);
	// while (map[i])
	// {
	// 	if (map_len != ft_strlen(map[i]))
	// 		ft_error("map not rectangle ");
	// 	i++;
	// }
	// while (map[i - 1][j] && map[0][j])
	// {
	// 	if (map[i - 1][j] != '1' || map[0][j] != '1')
	// 		ft_error("up and down ");
	// 	j++;
	// }
	// j = 1;
	// while (map[j])
	// {
	// 	if (map[j][0] != '1' || map[j][map_len - 1] != '1')
	// 		ft_error("righ and left ");
	// 	j++;
	// }
	// i = 1;
	// while (map[i])
	// {
	// j = 0;
	// 	while (map[i][j])
	// 	{
	// 		if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1')
	// 			ft_error("items ");
	// 		j++;
	// 	}
	// 	i++;
	// }
	// i = 0;
	// check_map_items(&map[i]);
	// image_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/MARIO2.xpm", &i, &i);
	// mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, 64, 64);
	// image_ptr = mlx_xpm_file_to_image(mlx_ptr, "assets/player.xpm", &i, &i);
	// mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, 0, 0);
	draw_map (mlx_ptr, window_ptr, "assets/wall.xpm");
	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, window_ptr);
}

