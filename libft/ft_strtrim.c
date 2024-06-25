/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:35:14 by oliradet          #+#    #+#             */
/*   Updated: 2023/10/19 13:56:46 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	is_present(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		j;
	int		n;

	if (!s1 || !set)
		return ((char *)s1);
	i = 0;
	j = ft_strlen((char *)s1) - 1;
	n = 0;
	while (is_present(s1[i], set) == 1 && s1[i])
		i++;
	if (!s1[i])
	{
		str = ft_calloc(1, 1);
		return (str);
	}
	while (is_present(s1[j], set) == 1)
		j--;
	str = ft_calloc(1, j - i + 2);
	if (!str)
		return (NULL);
	while (i != j + 1)
		str[n++] = s1[i++];
	return (str);
}
