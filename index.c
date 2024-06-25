/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 11:16:41 by oliradet          #+#    #+#             */
/*   Updated: 2024/05/27 11:16:41 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	ft_posi_tab(int *tab, int val)
{
	int	i;

	i = 0;
	while (tab && tab[i] != val)
		i++;
	return (i + 1);
}

void	bubble_sort_two(int *tab, t_node *tmp)
{
	while (tmp)
	{
		tmp->index = ft_posi_tab(tab, tmp->val);
		tmp = tmp->next;
	}
}

void	buble_sort_index(t_node *stack)
{
	t_node	*tmp;
	int		i;
	int		j;
	int		*tab;

	tab = malloc(sizeof(int) * ft_number_node(stack));
	if (!tab)
		error();
	i = -1;
	tmp = stack;
	while (tmp && tab)
	{
		tab[++i] = tmp->val;
		tmp = tmp->next;
	}
	i = -1;
	while (++i < ft_number_node(stack) && tab)
	{
		j = -1;
		while (++j < ft_number_node(stack) - 1)
			if (tab[j] > tab[j + 1])
				ft_swap(&tab[j], &tab[j + 1]);
	}
	bubble_sort_two(tab, stack);
	free(tab);
}

void	ft_little_sort(t_node **a)
{
	if (ft_number_node(*a) == 2)
		if ((*a)->val > (*a)->next->val)
			ft_swap_first_node(*a);
	if (ft_number_node(*a) == 3)
	{
		if ((*a)->val > (*a)->next->val && (*a)->val > (*a)->next->next->val)
			ft_rotate_node(a, 1);
		if ((*a)->val > (*a)->next->val && (*a)->val < (*a)->next->next->val)
			ft_swap_first_node(*a);
		if ((*a)->val < (*a)->next->val && (*a)->val > (*a)->next->next->val)
			ft_reverse_rotate_node(a, 1);
		if ((*a)->val < (*a)->next->val && (*a)->val < (*a)->next->next->val
			&& (*a)->next->val > (*a)->next->next->val)
		{
			ft_swap_first_node(*a);
			ft_reverse_rotate_node(a, 1);
		}
	}
}
