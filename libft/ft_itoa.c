/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:13:15 by oliradet          #+#    #+#             */
/*   Updated: 2023/10/19 14:02:03 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char	*ft_itoa_helper(int n, char *str)
{
	if (n >= 10)
		str = ft_itoa_helper(n / 10, str);
	*str++ = '0' + (n % 10);
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		temp;

	temp = n;
	len = 0;
	if (n <= 0)
		len = 1;
	while (temp != 0 && len ++ > -2147483647)
		temp /= 10;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = (char *)ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		ft_itoa_helper(-n, str + 1);
	}
	else
		ft_itoa_helper(n, str);
	return (str);
}
