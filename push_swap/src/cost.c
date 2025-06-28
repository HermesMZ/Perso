/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/06/28 05:05:20 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cost	*init_empty_cost(void)
{
	t_cost	*cost;
	
	cost = malloc(sizeof(t_cost));
	if (!cost)
		return (NULL);
	cost->ra = 0;
	cost->rb = 0;
	cost->rr = 0;
	cost->total = -1;
	cost->elem_b = NULL;
	return (cost);
}

t_cost	*calculate_node_cost(t_swap *swap, t_swap_int *elem_b)
{
	t_cost		*cost;
	t_swap_int	*target_a;

	target_a = get_target_in_a(swap->stack_a, elem_b);
	cost = init_empty_cost();
	cost->ra = r_or_rr(target_a);
	cost->rb = r_or_rr(elem_b);
	if (cost->ra > 0 && cost->rb > 0)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	if (cost->ra < 0 && cost->rb < 0)
	{
		cost->rr = ft_max(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr);
	cost->elem_b = elem_b;
	return (cost);
}

t_swap_int	*get_target_in_a(t_stack *stack_a, t_swap_int *elem_b)
{
	t_swap_int	*current_a;
	t_swap_int	*min;

	current_a = stack_a->first;
	min = find_index(stack_a, stack_a->min);
	if (stack_a->len == 0)
		return (0);
	if (elem_b->index < stack_a->min || elem_b->index > stack_a->max)
	{
		if (elem_b->index > stack_a->max)
			return (find_index(stack_a, stack_a->max));
		return (find_index(stack_a, stack_a->min));
	}
	while (current_a)
	{
		if (current_a->index < elem_b->index
			&& current_a->next->index > elem_b->index)
			return (current_a->next);
		if (current_a->index == stack_a->max && elem_b->index < stack_a->min)
			return (current_a);
		current_a = current_a->next;
	}
	return (0);
}

t_cost	*get_cost(t_cost *c1, t_cost *c2)
{
	if (c1->total == -1)
		return (c2);
	if (c2->total == -1)
		return (c1);
	if (c1->total <= c2->total)
		return (c1);
	return (c2);
}

void	push_back_to_a_optimized(t_swap *swap)
{
	t_swap_int	*current_b_node;
	t_cost		*cheapest_cost;
	t_cost		*current_cost;
	size_t		i;

	while (swap->stack_b->len > 0)
	{
		i = 0;
		cheapest_cost = init_empty_cost();
		current_b_node = swap->stack_b->first;
		while (i < swap->stack_b->len)
		{
			current_cost = calculate_node_cost(swap, current_b_node);
			cheapest_cost = get_cost(cheapest_cost, current_cost);
			current_b_node = current_b_node->next;
			i++;
		}
		execute_optimal_moves(swap, cheapest_cost);
	}
}
