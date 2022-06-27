/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:40:28 by aadnane           #+#    #+#             */
/*   Updated: 2022/06/27 22:55:26 by aadnane          ###   ########.fr       */
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

// int    ft_strncmp(char *s1, char *s2, unsigned int n)
// {
//     unsigned int    i;

//     i = 0;
//     if (n == 0)
//     return (0);
//         while ((s1[i] == s2[i] && s1[i] != '\0') && (i < n - 1))
//             i++;
//     return (s1[i] - s2[i]);
// }

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return(i);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
		return (s1[i] - s2[i]);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	int		i;
	int		j;
	char	*str;

	str = NULL;
	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
}