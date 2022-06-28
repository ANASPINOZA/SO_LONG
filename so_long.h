/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:57:40 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/28 17:43:49 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
# define PIXEL 64

typedef struct s_images
{
	void    *wall_img;
	void    *ground_img;
	void    *player_img;
	void    *player_img2;
	void    *flag_img;
	void    *x_img;
	void    *coin_img;
	void    *coin_img2;
}t_images;

typedef struct s_game
{
	char				**map;
	char				**map_chk;
	int					dead;
	int					rorl;
	int					anim;
	int					move_count;
	int					px;
	int					py;
	int					coin_count;
	int					map_width;
	int					map_height;
	struct s_images		images;
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
}t_game;


char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strchr(const char *s, int c);
char	*get_map(int ac, char **av);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
void	ft_error(char *status);
int     ft_strcmp(char *s1, char *s2);
void    draw_map (void *mlx_ptr, void *window_ptr, char *image_path, char **map);
void	check_map_items(char **map, t_game *data);
int     map_read_check(int ac, char **av);
char    **check_map(t_game *data, int ac, char **av);
void    check_walls(char **map, int i,int j, int map_len, t_game *data);
int     ft_chr_count(const char *s, int c);
void	ft_load_images(t_game *data);
void	render(t_game *data);
void	ft_switch_img(t_game *data, int x, int y);
void	game_check(t_game *data, int x, int y);
void	ft_putnbr(int n);
void    moves(int moves);
void    ft_putchar(char c);
int		destroy_notify(t_game *data);
int		ft_atoi(const char *str);

#endif
