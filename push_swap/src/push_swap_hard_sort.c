/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_hard_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 01:15:54 by zoum              #+#    #+#             */
/*   Updated: 2025/06/19 01:16:20 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	hard_sort_3(t_swap *swap, t_swap_int *elem)
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
	if (count == 2)
	{
		if (elem->index > elem->next->index)
			ft_swap(swap, elem);
	}
	else if (count == 3)
		hard_sort_3(swap, elem);
}