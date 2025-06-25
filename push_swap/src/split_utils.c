/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:25:09 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 00:54:57 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_int	*find_min_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*min;
	int			i;
	t_swap_int	*current;

	min = elem;
	current = elem;
	i = 0;
	while (i < count)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}

t_swap_int	*find_max_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*max;
	int			i;
	t_swap_int	*current;

	current = elem;
	max = elem;
	i = 0;
	while (i < count)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

t_swap_int	*find_pushed_head_split(t_swap_int *pivot, int count)
{
	t_swap_int	*current;
	int			i;
	t_swap_int	*pushed;

	i = 0;
	current = pivot->stack->first;
	pushed = current;
	while (i < count)
	{
		if (current->value > pivot->value)
			pushed = current;
		current = current->next;
		i++;
	}
	return (pushed);
}

t_swap_int	*find_remaining_head_split(t_swap_int *pivot)
{
	t_swap_int	*current;

	current = pivot->stack->first;
	while (current->index > pivot->index)
		current = current->next;
	return (current);
}

// prendre les heads finales 
// t_swap_int	*find_pushed_head_split(t_swap *swap, t_swap_int *pivot, int count)
// {
// 	t_swap_int	*current;

// 	ft_printf("pus\n");
// 	current = pivot->stack->first;
// 	ft_printf("pivot %d\n", pivot->value);
// 	if (pivot->stack == swap->stack_a)
// 		current = find_index(pivot->stack, pivot->index + 1);
// 	else
// 		current = find_max_in_split(pivot->stack->first, count);
// 	ft_printf("hed\n");

// 	return (current);
// }

// t_swap_int	*find_remaining_head_split(t_swap *swap, t_swap_int *pivot, int count)
// {
// 	t_swap_int	*current;

// 	ft_printf("bouh\n");
// 	current = pivot->stack->first;
// 	ft_printf("pivot %d\n", pivot->value);
// 	if (pivot->stack == swap->stack_a)
// 		find_min_in_split(pivot->stack->first, count);
// 	else
// 		current = pivot;
// 	ft_printf("teille\n");

// 	return (current);
// }


