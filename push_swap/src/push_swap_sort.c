/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/17 22:04:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_split(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;

	i = 0;
	rotate_to(swap, first);
	if (count > 2)
	{
		pivot = first;
		current = pivot->stack->first;
		while (i < count)
		{
			ft_printf("current : %d, pivot : %d\n", current->value, pivot->value);
			if (current->value >= pivot->value)
			{
				ft_printf("stack_split if\n");
				
				ft_push(swap, current);
				current = current->next;
			}
			else
			{
				ft_printf("stack_split else\n");
				debug_print_stacks(swap);
				ft_rotate(swap, pivot);
				current = current->next;
			}
			i++;
		}

		stack_split(swap, swap->stack_a->first, count);
		stack_split(swap, swap->stack_b->first, count);
	}
	if (current->value > current->next->value)
	{
		ft_printf("stack_split swap\n");
		ft_swap(swap, current);
	}
}

void	hard_sort_3(t_swap *swap, t_swap_int *elem)
{
	if (elem->stack == swap->stack_a)
	{
		if (elem->index > elem->next->index)
			ft_swap(swap, elem);
		if (elem->next->index > elem->next->next->index)
		{
			ft_rotate(swap, elem);
			ft_swap(swap, elem);
			ft_reverse_rotate(swap, elem);
		}
		if (elem->index > elem->next->index)
			ft_swap(swap, elem);
	}
}
