/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 12:10:45 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_int	*get_target(t_swap *swap, t_swap_int *source)
{
	if (source->stack == swap->stack_a)
		return (get_target_in_b(swap->stack_b, source));
	else
		return (get_target_in_a(swap->stack_a, source));
}

t_swap_int	*get_target_in_a(t_stack *stack_a, t_swap_int *elem_b)
{
	t_swap_int	*current_a;

	if (!stack_a || stack_a->len == 0)
		return (NULL);
	current_a = stack_a->first;
	if (elem_b->index < stack_a->min || elem_b->index > stack_a->max)
		return (find_index(stack_a, stack_a->min));
	while (current_a && current_a->next)
	{
		if (current_a->index < elem_b->index
			&& elem_b->index < current_a->next->index)
			return (current_a->next);
		if (current_a->index == stack_a->max && elem_b->index < stack_a->min)
			return (stack_a->first);
		current_a = current_a->next;
	}
	return (NULL);
}

t_swap_int	*get_target_in_b(t_stack *stack_b, t_swap_int *elem_a)
{
	t_swap_int	*current_b;
	t_swap_int	*target_b;
	size_t		i;

	target_b = NULL;
	if (stack_b->len == 0)
		return (NULL);
	current_b = stack_b->first;
	i = 0;
	while (i < stack_b->len)
	{
		if (current_b->index < elem_a->index
			&& current_b->prev->index > elem_a->index)
		{
			target_b = current_b;
			break ;
		}
		current_b = current_b->next;
		i++;
	}
	return (target_b);
}

t_cost	*calculate_cost(t_swap *swap, t_swap_int *current,
	t_cost *cheapest_cost)
{
	t_cost		*current_cost;

	if (current->stack == swap->stack_a)
		current_cost = calculate_cost_for_a_to_b(swap, current);
	else
		current_cost = calculate_cost_for_b_to_a(swap, current);
	if (!current_cost)
		return (free_cost_if_not_null(&cheapest_cost), (t_cost *) NULL);
	if (!cheapest_cost || current_cost->total < cheapest_cost->total)
	{
		free_cost_if_not_null(&cheapest_cost);
		cheapest_cost = current_cost;
	}
	else
		free_cost_if_not_null(&current_cost);
	return (cheapest_cost);
}

t_cost	*find_cheapest_element(t_swap *swap, t_stack *source_stack,
	int chunk_min, int chunk_max)
{
	t_swap_int	*current;
	t_cost		*cheapest_cost;
	size_t		i;

	cheapest_cost = NULL;
	current = source_stack->first;
	i = 0;
	while (i < source_stack->len)
	{
		if ((source_stack == swap->stack_a
				&& (current->index >= chunk_min
					&& current->index <= chunk_max))
			|| (source_stack == swap->stack_b))
			cheapest_cost = calculate_cost(swap, current, cheapest_cost);
		current = current->next;
		i++;
	}
	return (cheapest_cost);
}
