/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oliradet <oliradet@42student.perpignan.f>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:48:56 by oliradet          #+#    #+#             */
/*   Updated: 2024/04/07 12:48:56 by oliradet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <malloc.h>

typedef struct s_node
{
	int				val;
	int				index;
	int				check;
	struct s_node	*next;
}	t_node;

t_node	*ft_lst_last(t_node *lst);
void	ft_lst_add_back(t_node **lst, t_node *new);
void	ft_fill_lst(t_node **lst, int argc, char **argv);
void	ft_free_lst(t_node **lst);
void	error(void);
void	ft_check_error(int argc, char **argv);
void	ft_swap_first_node(t_node *a);
void	ft_rotate_node(t_node **a, int etat);
void	ft_push_node(t_node **a, t_node **b, int etat);
void	ft_reverse_rotate_node(t_node **a, int etat);
int		ft_number_node(t_node *a);
int		ft_smallest(t_node *a);
int		ft_posi(t_node *a, int val);
int		ft_is_sort(t_node *a);
void	buble_sort_index(t_node *stack);
int		ft_number_node(t_node *a);
void	bubble_sort_two(int *tab, t_node *tmp);
void	ft_little_sort(t_node **a);
void	ft_mid_sort(t_node **a);

#endif//PUSH_SWAP_H