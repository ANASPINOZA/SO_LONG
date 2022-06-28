/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:15:56 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/28 15:52:42 by aadnane          ###   ########.fr       */
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

int destroy_notify(t_game *data)
{
	(void)data;
	ft_putstr("\nGAME CLOSED SUCCESSFULLY\n");
	exit(0);
	return (1);
}

char	*display_moves(char * statement, int nb)
{
	(void)statement;
	(void)nb;
	return (NULL);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	base;
	int	sign;

	i = 0;
	sign = 1;
	base = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\n'
			|| str[i] == '\t' || str[i] == '\r'
			|| str[i] == '\f' || str[i] == '\v'))
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		base = base * 10 + (str[i] - '0');
		i++;
	}
	return (base * sign);
}