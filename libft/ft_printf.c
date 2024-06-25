/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:14:29 by oliradet          #+#    #+#             */
/*   Updated: 2023/10/27 17:14:29 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_arg(va_list arg, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (c == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (c == 'p')
		return (ft_putptr(va_arg(arg, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	if (c == 'u')
		return (ft_putunbr(va_arg(arg, unsigned int)));
	if (c == 'x')
		return (ft_putlohexa(va_arg(arg, unsigned int)));
	if (c == 'X')
		return (ft_putuphexa(va_arg(arg, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		len;

	va_start(arg, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		while (str[i] != '%' && str[i])
		{
			i += ft_putchar(str[i]);
			len++;
		}
		if (str[i] == '%')
		{
			i++;
			len += ft_printf_arg(arg, str[i]);
			i++;
		}
	}
	return (len);
}
