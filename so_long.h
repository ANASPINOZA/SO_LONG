/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:57:40 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/23 16:53:08 by aadnane          ###   ########.fr       */
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
	void    *flag_img;
	void    *coin_img;
}t_images;

typedef struct s_game
{
	char				**map;
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
// int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*get_map(int ac, char **av);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
void	ft_putstr(char *str);
void	ft_error(char *status);
int     ft_strcmp(char *s1, char *s2);
void    draw_map (void *mlx_ptr, void *window_ptr, char *image_path, char **map);
void	check_map_items(char **map);
int     map_read_check(int ac, char **av);
char    **check_walls(t_game *data, int ac, char **av);
void    check_map(char **map, int i,int j, int map_len);
int     ft_chr_count(const char *s, int c);
void	ft_load_images(t_game *data);
void	render(t_game data);


#endif
