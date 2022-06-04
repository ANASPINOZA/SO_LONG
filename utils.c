/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:40:28 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/04 17:17:10 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

int    ft_strncmp(char *s1, char *s2, unsigned int n)
{
    unsigned int    i;

    i = 0;
    if (n == 0)
    return (0);
        while ((s1[i] == s2[i] && s1[i] != '\0') && (i < n - 1))
            i++;
    return (s1[i] - s2[i]);
}

int		ft_strlen(char *str)
{
	int i;

	while (str[i])
		i++;
		return(i);
}
