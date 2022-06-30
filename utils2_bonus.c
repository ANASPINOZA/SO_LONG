/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 18:51:13 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/30 14:07:14 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	moves_catcher(int moves)
{
	int	i;

	i = 0;
	i++;
	moves = i;
	return (moves);
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

char	*display_moves(int nb, t_game *data)
{
	data->c = ft_itoa(nb);
	return (data->c);
}

void	intial_vars(t_game *data)
{
	data->move_count = 0;
	data->anim = 0;
}
