/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:15:56 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/28 23:47:43 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    moves(int moves)
{
    ft_putchar('\n');
    ft_putstr("move :");
    ft_putnbr(moves);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

int	destroy_notify(t_game *data)
{
	(void)data;
	ft_putstr("\nGAME CLOSED SUCCESSFULLY\n");
	exit(0);
	return (1);
}

char	*display_moves(int nb, t_game *data)
{
	data->c = ft_itoa(nb);
	return (data->c);
}
