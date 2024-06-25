/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:05:30 by oliradet          #+#    #+#             */
/*   Updated: 2023/10/12 12:36:46 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t len)
{
	char	*h;
	size_t	needle_len;
	size_t	j;
	size_t	i;

	h = (char *)str;
	needle_len = ft_strlen(to_find);
	if (!(needle_len))
		return (h);
	if ((size_t)ft_strlen(str) < needle_len || len < needle_len)
		return (NULL);
	i = 0;
	while (h[i] && i <= len - needle_len)
	{
		j = 0;
		while (to_find[j] && to_find[j] == h[i + j])
			j++;
		if (j == needle_len)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
