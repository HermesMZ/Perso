/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 17:04:21 by zoum              #+#    #+#             */
/*   Updated: 2025/06/19 00:57:21 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_swap *swap, t_swap_int *elem)
{
	if (!swap || !elem || elem->stack->len < 2)
		return ;
	elem->stack->first = elem->stack->first->prev;
	elem->stack->last = elem->stack->last->prev;
	if (elem->stack == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rra\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rrb\n")));
}

void	ft_reverse_rotate_rr(t_swap *swap)
{
	ft_reverse_rotate(swap, swap->stack_a->first);
	ft_reverse_rotate(swap, swap->stack_b->first);
}
// traiter les rrr au tri de fin