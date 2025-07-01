/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/07/01 22:15:22 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_cost_if_not_null(t_cost **cost)
{
	if (*cost)
	{
		free(*cost);
		*cost = NULL;
	}
}

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
// ft_printf("calculate_node_cost\n");
	target_a = get_target_in_a(swap->stack_a, elem_b);
	cost = init_empty_cost();
	if (!cost)
		return (NULL);
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
		// ft_printf("get_target_in_a %d\n", elem_b->index);

	if (!stack_a || stack_a->len == 0)
	{
		// ft_printf("!stack_a || stack_a->len == 0\n");
		
		return (NULL);
	}
	current_a = stack_a->first;
	if (elem_b->index < stack_a->min || elem_b->index > stack_a->max)
	{
		// ft_printf("target min max %d %d\n", stack_a->min, stack_a->max);
		return (find_index(stack_a, stack_a->min));
	}
	while (current_a && current_a->next)
	{
		// ft_printf("target loop\n");
		
		if (current_a->index < elem_b->index
			&& elem_b->index < current_a->next->index)
			return (current_a->next);
		if (current_a->index == stack_a->max && elem_b->index < stack_a->min)
			return (stack_a->first);
		current_a = current_a->next;
		
	}
	return (NULL);
}


void	push_back_to_a_optimized(t_swap *swap)
{
	t_swap_int	*current_b_node;
	t_cost		*cheapest_cost = NULL;
	t_cost		*current_cost = NULL;
	size_t		i;

	// ft_printf("push_back\n");
	while (swap->stack_b->len > 0)
	{
		i = 0;
		current_b_node = swap->stack_b->first;
		free_cost_if_not_null(&cheapest_cost);
		while (i < swap->stack_b->len)
		{
			current_cost = calculate_node_cost(swap, current_b_node);
			if (!current_cost)
				return (free_cost_if_not_null(&cheapest_cost));
			if (!cheapest_cost || current_cost->total < cheapest_cost->total)
			{
				free_cost_if_not_null(&cheapest_cost);
				cheapest_cost = current_cost;
			}
			else
				free_cost_if_not_null(&current_cost);
			current_b_node = current_b_node->next;
			i++;
		}
		// ft_printf("current_cost %d\n", cheapest_cost->total);
		execute_optimal_moves(swap, cheapest_cost);
		// debug_print_stacks(swap);
	}
	free_cost_if_not_null(&cheapest_cost);
}
