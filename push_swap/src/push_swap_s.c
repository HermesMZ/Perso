/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:39:06 by zoum              #+#    #+#             */
/*   Updated: 2025/06/19 00:57:04 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_swap *swap, t_swap_int *elem)
{
	t_swap_int	*first;
	t_swap_int	*second;
	t_swap_int	*third;

	if (!swap || !elem || elem->stack->len < 2)
		return ;
	first = elem->stack->first;
	second = first->next;
	third = second->next;
	first->next = third;
	first->prev = second;
	second->next = first;
	second->prev = first->stack->last;
	third->prev = first;
	elem->stack->last->next = second;
	elem->stack->first = second;
	if (elem->stack == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("sa\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("sb\n")));
}

void	ft_swap_ss(t_swap *swap)
{
	if (!swap)
		return ;
	ft_swap(swap, swap->stack_a->first);
	ft_swap(swap, swap->stack_b->first);
}
// traiter les ss au tri de fin
