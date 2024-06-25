/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_more_printer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@student.42perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 18:14:47 by oliradet          #+#    #+#             */
/*   Updated: 2023/10/28 18:14:47 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(unsigned long long n)
{
	int	i;

	if (!n)
		return (ft_putstr("(nil)"));
	i = ft_putstr("0x");
	i += ft_putlohexa_spe(n);
	return (i);
}

int	ft_putlohexa_spe(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putlohexa_spe(n / 16);
		i += ft_putlohexa_spe(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
			i += ft_putchar(n + 'a' - 10);
	}
	return (i);
}

int	ft_putunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 10)
	{
		i += ft_putunbr(n / 10);
		i += ft_putunbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	ft_putlohexa(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putlohexa(n / 16);
		i += ft_putlohexa(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
			i += ft_putchar(n + 'a' - 10);
	}
	return (i);
}

int	ft_putuphexa(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += ft_putuphexa(n / 16);
		i += ft_putuphexa(n % 16);
	}
	else
	{
		if (n < 10)
			i += ft_putchar(n + '0');
		else
			i += ft_putchar(n + 'A' - 10);
	}
	return (i);
}
