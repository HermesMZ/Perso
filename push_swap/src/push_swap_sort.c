/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 21:05:25 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot,
	t_swap_int **current, int *push_count)
{
	t_swap_int	*last_pushed;

	last_pushed = NULL;
	ft_printf("current index %d pivot %d ", (*current)->index, pivot->index);
	if ((*current)->index >= pivot->index)
	{
		ft_printf("push\n");
		last_pushed = (*current);
		(*current) = (*current)->next;
		ft_push(swap, last_pushed);
		(*push_count)++;
	}
	else if ((*current)->index < pivot->index)
	{
		ft_printf("rotate\n");

		ft_rotate(swap, (*current));
		(*current) = (*current)->next;
	}
	debug_print_stacks(swap);
	return (last_pushed);
}

// static void	stack_merge(t_swap *swap, t_elem *elem, int count)
// {
	
// }

void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;
	int			push_count;
	t_swap_int	*last_pushed;

	push_count = 0;
	i = 0;
	rotate_to(swap, first);
		ft_printf("\n ========================== NEW CALL ==============================\n");
		
		debug_print_stacks(swap);
		ft_printf(" ==================================================================\n");
	
	if (count > 1)
	{
		pivot = find_median(first, count);
		ft_printf(" =========================== pivot : %d count : %d ===========================\n", pivot->value, count);
		current = first;
		while (i < count)
		{
			last_pushed = stack_split(swap, pivot, &current, &push_count);
			i++;
		}
		// debug_print_stacks(swap);
		quick_sort_stack(swap, last_pushed, push_count);
		quick_sort_stack(swap, current, count - push_count);
		ft_printf(" ================== fin de recursive ==================\n");
	}
	else
	{
	if (first->index > first->next->index && first->stack == swap->stack_a)
	{
		ft_printf("swap\n");
		ft_swap(swap, first);
	}
	if (first->index < first->next->index && first->stack == swap->stack_b)
	{
		ft_printf("swap\n");
		ft_swap(swap, first);
	}
}
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
