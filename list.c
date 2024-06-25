/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 16:18:31 by oliradet          #+#    #+#             */
/*   Updated: 2024/04/09 16:18:31 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lst_last(t_node *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_lst_add_back(t_node **lst, t_node *new)
{
	t_node	*last;

	if (!lst || !new)
		return ;
	last = ft_lst_last(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

void	ft_fill_lst(t_node **lst, int argc, char **argv)
{
	int		i;
	t_node	*new;

	if (!lst || !argv)
		return ;
	i = 1;
	while (i <= argc)
	{
		if (!argv[i])
			return ;
		new = malloc(sizeof(t_node));
		if (!new)
			return ;
		new->val = ft_atoi(argv[i]);
		new->next = NULL;
		new->index = i;
		ft_lst_add_back(lst, new);
		i++;
	}
}

/**
 * free the list
 * @param lst
 */
void	ft_free_lst(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_number_of_node(t_node *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
