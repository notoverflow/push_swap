/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:04:29 by oliradet          #+#    #+#             */
/*   Updated: 2024/04/05 00:55:49 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * a strlenn lol
 * @param str
 * @return
 */
int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/**
 * libft
 * @param str
 * @return
 */
char	*ft_strdup(char *str)
{
	char	*d;
	int		i;

	d = malloc(ft_strlenn(str) * sizeof(char) + 1);
	if (d == NULL)
		return (NULL);
	i = 0;
	while (str[i])
	{
		d[i] = str[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/**
 * :'(
 * @param s1
 * @param s2
 * @return
 */
char	*ft_strjoingnl(char *s1, char *s2)
{
	char	*res;
	size_t	len_one;
	size_t	len_two;
	size_t	i;

	len_one = ft_strlenn(s1);
	len_two = ft_strlenn(s2);
	res = (char *)malloc(sizeof(char) * (len_one + len_two + 1));
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	i = -1;
	while (++i < len_one)
		res[i] = s1[i];
	i--;
	while (++i < len_one + len_two)
		res[i] = s2[i - len_one];
	res[i] = '\0';
	free(s1);
	return (res);
}
