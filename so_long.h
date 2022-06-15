/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:57:40 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/15 14:15:20 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HIGHT 640

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
void    draw_map (void *mlx_ptr, void *window_ptr, char *image_path);
void	check_map_items(char **map);
int     map_read_check(int ac, char **av);
void    check_walls(int ac, char **av, void *mlx_ptr, void *window_ptr);
char    **check_map(char **map, int i,int j, int map_len);
int     ft_chr_count(const char *s, int c);


#endif