/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 18:41:42 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/15 13:49:31 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **check_map(char **map, int i,int j, int map_len)
{
    	while (map[i - 1][j++] && map[0][j])
	{
		if (map[i - 1][j] != '1' || map[0][j] != '1')
			ft_error("above or bottom ");
	}
	j = 0;
	while (map[++j])
	{
		if (map[j][0] != '1' || map[j][map_len - 1] != '1')
			ft_error("righ side or left side");
	}
	i = 0;
	while (map[++i])
	{
	j = -1;
		while (map[i][++j])
		{
			if (map[i][j] != 'C' && map[i][j] != 'P' && map[i][j] != 'E' && map[i][j] != '0' && map[i][j] != '1')
				ft_error("items ");
		}
	}
    i = 0;
	check_map_items(&map[i]);
    return(&map[0]);
}

int	ft_chr_count(const char *s, int c)
{
    int count;
    
    count = 0;
	while (*s)
	{
		if (*s == (unsigned char)c)
            count++;
		s++;
	}
    return (count);
}

// int main()
// {
//     char *s = "aaaaaaakaaakaaaak";
//     char *d = "aaaaaaakaaakakkaaak";
//     char *f = "aaaaaaaaaakaaaak";
//     printf("%d", ft_chr_count(s, 'k'));
//     printf("%d", ft_chr_count(d, 'k'));
//     printf("%d", ft_chr_count(f, 'k'));
// }