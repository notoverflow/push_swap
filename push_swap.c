/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:31:01 by oliradet          #+#    #+#             */
/*   Updated: 2024/06/20 14:14:09 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * check if the input is a number, a int and not duplicated
 * @param argc my number of arguments
 * @param argv my arguments
 */
void	ft_check_error(int argc, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		while (argv[i][j])
			if (!ft_isdigit(argv[i][j++]))
				error();
		k = i + 1;
		while (k < argc)
		{
			if (ft_atoi(argv[i]) == ft_atoi(argv[k]))
				error();
			if (ft_atoi(argv[i]) >= 2147483647L
				|| ft_atoi(argv[i]) <= -2147483648L)
				error();
			k++;
		}
		i++;
	}
}

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	raddix(t_node **a, t_node **b, int i)
{
	int	n;
	int	ptr;

	n = ft_number_node(*a);
	while (n != 0)
	{
		ptr = (*a)->index;
		if (!(ptr & (1 << i)))
			ft_push_node(a, b, 2);
		else
			ft_rotate_node(a, 1);
		n--;
	}
	while (*b)
		ft_push_node(a, b, 1);
}

void	ft_sort(t_node **a)
{
	t_node	*b;
	int		i;

	b = NULL;
	i = 0;
	while (!ft_is_sort(*a))
	{
		raddix(a, &b, i);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_node	*a;

	a = NULL;
	if (argc < 2)
		return (0);
	ft_check_error(argc, argv);
	ft_fill_lst(&a, argc, argv);
	buble_sort_index(a);
	if (ft_number_node(a) <= 3)
		ft_little_sort(&a);
	else if (ft_number_node(a) <= 5)
		ft_mid_sort(&a);
	else
		ft_sort(&a);
	ft_free_lst(&a);
	return (0);
}
