/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 14:31:10 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_split(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;
	static int	z = 0;

	while (z < 1)
	{
		
	i = 0;
	rotate_to(swap, first);
	if (count > 2)
	{
	z++;

		pivot = first;
		current = pivot->stack->first;
		while (i < count)
		{
			ft_printf("current : %d, pivot : %d\n", current->value, pivot->value);
			while (current->index >= pivot->index)
			{
				// ft_printf("stack_split if\n");
				
				ft_push(swap, current);
				current = current->next;
			}
			while (current->index < pivot->index)
			{
				debug_print_stacks(swap);
				ft_rotate(swap, pivot);
				current = current->next;
			}
			i++;
		}
				ft_printf("stack_split else\n");

		
				stack_split(swap, swap->stack_b->first, count);
				stack_split(swap, swap->stack_a->first, count);

	}
	else if (current->value > current->next->value)
	{
		ft_printf("stack_split swap\n");
		ft_swap(swap, current);
	}
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
