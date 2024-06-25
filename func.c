/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:25:49 by oliradet          #+#    #+#             */
/*   Updated: 2024/05/18 17:25:49 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_smallest(t_node *a)
{
	int	min;

	min = a->val;
	while (a)
	{
		if (a->val < min)
			min = a->val;
		a = a->next;
	}
	return (min);
}

int	ft_number_node(t_node *a)
{
	int	i;

	i = 0;
	while (a != NULL)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	ft_is_sort(t_node *a)
{
	while (a->next)
	{
		if (a->next->val < a->val)
			return (0);
		a = a->next;
	}
	return (1);
}

int	ft_posi(t_node *a, int val)
{
	t_node	*ttt;
	int		i;

	ttt = a;
	i = 0;
	while (a->next != NULL && a->val != val)
	{
		a = a->next;
		i++;
	}
	if (i >= ft_number_node(ttt) / 2)
		return (0);
	return (1);
}

void	ft_mid_sort(t_node **a)
{
	t_node	*b;
	int		min;

	b = NULL;
	while (ft_number_node(*a) > 3)
	{
		min = ft_smallest(*a);
		if ((*a)->val == min)
			ft_push_node(a, &b, 2);
		else
			ft_rotate_node(a, 1);
	}
	ft_little_sort(a);
	while (b)
		ft_push_node(a, &b, 1);
}
