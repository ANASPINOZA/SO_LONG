#include "so_long.h"

// while (x < 325 && y < 175)
	// {
	// 	if (((x >= 275 && x <= 325) && (y == 125 || y == 174)) || ((y > 125 && y < 175) && (x == 275 || x == 324)))
	// 		mlx_pixel_put(mlx_ptr, window_ptr, x, y, 0x00FF0000);
	// 	x++;
	// 	if(x == 325)
	// 	{
	// 		x = 275;
	// 		y++;	
	// 	}
	// }


	void draw_map (void *mlx_ptr, void *window_ptr, char *image_path)
	{
		int xVar;
		int yVar;
		int img_size;
		int window_width;
		int i;
		void *image_ptr;

		xVar = 0;
		yVar = 0;
		i = 0;
		img_size = 64;
		window_width = 1280;
		while (i < (window_width / img_size))
		{
			image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_size, &img_size);
			mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, xVar, yVar);
			xVar += img_size;
			i++;
		}
		yVar = 	WINDOW_HIGHT - 64;
		i = 0;
		xVar = 0;
		while (i < (WINDOW_WIDTH / img_size))
		{
			image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_size, &img_size);
			mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, xVar, yVar);
			xVar += img_size;
			i++;
		}
		i = 0;
		yVar = 64; 
		xVar = 0;
		while (i < (WINDOW_HIGHT / img_size))
		{
			image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_size, &img_size);
			mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, xVar, yVar);
			yVar += img_size;
			i++;
		}
		i = 0;
		yVar = 64; 
		xVar = WINDOW_WIDTH - 64;
		while (i < (WINDOW_HIGHT / img_size))
		{
			image_ptr = mlx_xpm_file_to_image(mlx_ptr, image_path, &img_size, &img_size);
			mlx_put_image_to_window(mlx_ptr, window_ptr, image_ptr, xVar, yVar);
			yVar += img_size;
			i++;
		}
	}