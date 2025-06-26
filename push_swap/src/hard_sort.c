/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 01:34:29 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	hard_sort_3(t_swap *swap, t_swap_int *elem, int ascending)
{
	if ((ascending && elem->index > elem->next->index)
		|| (!ascending && elem->index < elem->next->index))
	{
		ft_swap(swap, elem);
		elem = elem->stack->first;
	}
	if ((ascending && elem->next->index > elem->next->next->index)
		|| (!ascending && elem->next->index < elem->next->next->index))
	{
		ft_rotate(swap, elem);
		ft_swap(swap, elem);
		ft_reverse_rotate(swap, elem);
		elem = elem->stack->first;
	}
	if ((ascending && elem->index > elem->next->index)
		|| (!ascending && elem->index < elem->next->index))
		ft_swap(swap, elem);
}

void	hard_sort(t_swap *swap, t_swap_int *elem, int count)
{
	t_swap_int	*to;
	
	rotate_to(swap, elem);
	// ft_printf("SORT\n");
	// debug_print_stacks(swap);
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
	if (count == 3)
		hard_sort_3(swap, elem, elem->stack == swap->stack_a);
	// ft_printf("SORTiiiiiiii");
	// debug_print_stacks(swap);
}
