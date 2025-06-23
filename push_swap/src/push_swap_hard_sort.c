/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hard_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/06/23 16:32:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_3_b(t_swap *swap, t_swap_int *elem)
{
	if (elem->index < elem->next->index)
	{
		ft_swap(swap, elem);
		elem = elem->stack->first;
	}
	if (elem->next->index < elem->next->next->index)
	{
		ft_rotate(swap, elem);
		ft_swap(swap, elem);
		ft_reverse_rotate(swap, elem);
		elem = elem->stack->first;
	}
	if (elem->index < elem->next->index)
		ft_swap(swap, elem);
}

void	hard_sort_3_a(t_swap *swap, t_swap_int *elem)
{
	if (elem->index > elem->next->index)
	{
		ft_swap(swap, elem);
		elem = elem->stack->first;
	}
	if (elem->next->index > elem->next->next->index)
	{
		ft_rotate(swap, elem);
		ft_swap(swap, elem);
		ft_reverse_rotate(swap, elem);
		elem = elem->stack->first;
	}
	if (elem->index > elem->next->index)
		ft_swap(swap, elem);
}

void	hard_sort(t_swap *swap, t_swap_int *elem, int count)
{
	t_swap_int	*to;

	ft_printf("hard_sort elem->value %d count %d\n", elem->value, count);
	if (!elem || !count)
		return ;
	if (elem->stack == swap->stack_b)
		to = swap->stack_b->first;
	else
		to = swap->stack_a->first;
	if (count == 2)
	{
		if ((to->index > to->next->index && to->stack == swap->stack_a)
			|| (to->index < to->next->index && to->stack == swap->stack_b))
			ft_swap(swap, to);
	}
	else if (count == 3)
	{
		if (to->stack == swap->stack_a)
			hard_sort_3_a(swap, to);
		else
			hard_sort_3_b(swap, to);
	}
}
