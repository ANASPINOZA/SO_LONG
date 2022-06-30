/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:15:56 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/30 00:29:11 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moves(int moves)
{
	ft_putchar('\n');
	ft_putstr("move :");
	ft_putnbr(moves);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

int	destroy_notify(t_game *data)
{
	ft_putstr("\nGAME CLOSED SUCCESSFULLY\n");
	end_game(data);
	return (1);
}

void	intial_vars(t_game *data)
{
	data->move_count = 0;
	data->anim = 0;
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}
