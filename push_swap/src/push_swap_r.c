/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 16:42:18 by zoum              #+#    #+#             */
/*   Updated: 2025/06/20 05:07:37 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_swap *swap, t_swap_int *elem)
{
	if (!swap || !elem || elem->stack->len < 2)
		return ;
	elem->stack->first = elem->stack->first->next;
	elem->stack->last = elem->stack->last->next;
	if (elem->stack == swap->stack_a)
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("ra\n")));
	else
		ft_lstadd_back(&swap->move, ft_lstnew(ft_strdup("rb\n")));
}

void	ft_rotate_rr(t_swap *swap)
{
	if (!swap)
		return ;
	ft_rotate(swap, swap->stack_a->first);
	ft_rotate(swap, swap->stack_b->first);
}
// traiter les rr au tri de fin
