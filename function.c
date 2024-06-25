/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:32:10 by oliradet          #+#    #+#             */
/*   Updated: 2024/02/23 17:32:10 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 *  swap the 2 first node of a list
 * @param a stack a
 */
void	ft_swap_first_node(t_node *a)
{
	int	tmp;

	tmp = a->val;
	a->val = a->next->val;
	a->next->val = tmp;
	ft_printf("sa\n");
}

/**
* push node
 * @param a stack a
 * @param b stack b
 * @param etat : \n
 * 	1:  take the first  node of  b and put it at the top of a (pa)\n
 * 		2:  take the first  node of  a and put it at the top of b (pb)\n
 */
void	ft_push_node(t_node **a, t_node **b, int etat)
{
	t_node	*tmp;

	if (etat == 1)
	{
		if (ft_number_node(*b) == 0)
			return ;
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
		ft_printf("pa\n");
	}
	else if (etat == 2)
	{
		if (*a == NULL)
			return ;
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
		ft_printf("pb\n");
	}
}

/**
 * rotate the list of node to the top
 * the first node become the last node
 * @param a stack a
 */
void	ft_rotate_node(t_node **a, int etat)
{
	t_node	*first;
	t_node	*last;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = first->next;
	first->next = NULL;
	last->next = first;
	if (etat == 1)
		ft_printf("ra\n");
	else if (etat == 2)
		ft_printf("rb\n");
}

/**
 * reverse rotate the list of node to the bottom
 * @param a stack a
 */
void	ft_reverse_rotate_node(t_node **a, int etat)
{
	t_node	*tmp;
	t_node	*tmp2;

	tmp = *a;
	if (tmp->next == NULL)
		return ;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp2 = tmp->next;
	tmp->next = NULL;
	tmp2->next = *a;
	*a = tmp2;
	if (etat == 1)
		ft_printf("rra\n");
	else if (etat == 2)
		ft_printf("rrb\n");
}
