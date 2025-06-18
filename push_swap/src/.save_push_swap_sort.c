/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 20:10:22 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_split(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;
	int			push_count;
	t_swap_int	*last_pushed;

	push_count = 0;
	i = 0;
	rotate_to(swap, first);
	if (count > 2)
	{
		pivot = find_median(first, count);
		current = first;
		while (i < count)
		{
			if (current->index >= pivot->index)
			{
				last_pushed = current;
				current = current->next;
				ft_push(swap, last_pushed);
				push_count++;
			}
			else if (current->index < pivot->index)
			{
				ft_rotate(swap, pivot);
				current = current->next;
			}
			i++;
		}
		stack_split(swap, last_pushed, push_count);
		stack_split(swap, current, count - push_count);
	}
	
	// hard_sort_3(swap, first);
}

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
