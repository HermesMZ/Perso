/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/19 16:42:54 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot,
	t_swap_int **current, int *push_count)
{
	t_swap_int	*last_pushed;
	t_swap_int	*next;

	if (!*current)
		return (NULL);
	next = (*current)->next;
	if (next->stack == swap->stack_a)
		last_pushed = swap->stack_b->first;
	else
		last_pushed = swap->stack_a->first;
	// ft_printf("current %d pivot %d \n", (*current)->value, pivot->value);
	if ((*current)->index >= pivot->index)
	{
		ft_push(swap, *current);
		last_pushed = *current;
		(*push_count)++;
	}
	else
		ft_rotate(swap, (*current));
	*current = next;
	// debug_print_stacks(swap);
	return (last_pushed);
}

static void	merge_split(t_swap *swap, t_swap_int *first, t_stack *to, int count)
{
	int			i;

	ft_printf(" ======================== MERGE ======================== \n");
	if (!first)
		return ((void)ft_printf("merge first is NULL\n"));
	if (!to)
	{
		if (first->stack == swap->stack_a)
			to = swap->stack_b;
		else
			to = swap->stack_a;
	}
	// ft_printf("first->value %d to->value %d \n", first->value, to_first->value);
	// debug_print_stacks(swap);

	i = 0;
	rotate_to(swap, first);
	rotate_to(swap, to->first);
	// debug_print_stacks(swap);

	while (i < count)
	{
		if (first->index < to->first->index && first->index > to->first->prev->index)
			ft_push(swap, first);
		else if (first->index > to->first->index && first->index < to->first->next->index)
		{
			ft_rotate(swap, to->first);
			ft_push(swap, first);
		}
		i++;
	}
	// debug_print_stacks(swap);
	ft_printf(" ========================= END ========================= \n");
}

t_stack	*recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	t_swap_int	*last_pushed;
	int			i;
	int			push_count;
	debug_print_stacks(swap);
	
	pivot = find_median(first, count);
	ft_printf(" =================NEW PIVOT = %d - count = %d ================== \n", pivot->value, count);
	current = first;
	push_count = 0;
	last_pushed = NULL;
	i = 0;
	while (i < count)
	{
		last_pushed = stack_split(swap, pivot, &current, &push_count);
		i++;
	}
	if (push_count > 0)
	{
		quick_sort_stack(swap, last_pushed, push_count);
		return (current->stack);
	}
	else if (count - push_count > 0)
	{
		quick_sort_stack(swap, current, count - push_count);
		return (last_pushed->stack);
	}
	return (NULL);
}

void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_stack	*to;

	to = NULL;
	if (!first)
		return ;
	rotate_to(swap, first);
	if (count > 1)
		to = recursive_split_call(swap, first, count);
	merge_split(swap, first, to, count);
}
