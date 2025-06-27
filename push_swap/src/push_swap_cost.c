/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/06/27 14:13:11 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	calc_min_rot(int pos, int len)
{
	if (pos <= len / 2)
		return (pos);
	return (pos - len);
}

t_cost	*init_empty_cost(void)
{
	t_cost	*cost;

	cost->ra = 0;
	cost->rb = 0;
	cost->rra = 0;
	cost->rrb = 0;
	cost->rr = 0;
	cost->rrr = 0;
	cost->total = -1;
	cost->node_b = NULL;
	return (cost);
}

t_cost	*get_cheapest_cost_struct(t_cost *c1, t_cost *c2)
{
	if (c1->total == -1)
		return (c2);
	if (c2->total == -1)
		return (c1);
	if (c1->total <= c2->total)
		return (c1);
	return (c2);
}

t_cost	*calculate_node_cost(t_swap *swap, t_swap_int *node_b)
{
	t_cost	*cost;
	int		target_idx_a;
	t_cost	*best_cost;

	target_idx_a = get_target_pos_in_a(swap->stack_a, node_b->value);
	cost = init_empty_cost();
	cost->ra = target_idx_a;
	cost->rb = node_b->index;
	if (cost->ra > 0 && cost->rb > 0)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->total = cost->ra + cost->rb + cost->rr;
	cost->node_b = node_b;
	best_cost = cost;
	cost = init_empty_cost();
	cost->rra = (swap->stack_a->len - target_idx_a) % swap->stack_a->len;
	cost->rrb = (swap->stack_b->len - node_b->index) % swap->stack_b->len;
	if (cost->rra > 0 && cost->rrb > 0)
	{
		cost->rrr = ft_min(cost->rra, cost->rrb);
		cost->rra -= cost->rrr;
		cost->rrb -= cost->rrr;
	}
	cost->total = cost->rra + cost->rrb + cost->rrr;
	cost->node_b = node_b;

	best_cost = get_cheapest_cost_struct(best_cost, cost);

	cost = init_empty_cost();
	cost->ra = target_idx_a;
	cost->rrb = (swap->stack_b->len - node_b->index) % swap->stack_b->len;
	cost->total = cost->ra + cost->rrb;
	cost->node_b = node_b;

	best_cost = get_cheapest_cost_struct(best_cost, cost);

	cost = init_empty_cost();
	cost->rra = (swap->stack_a->len - target_idx_a) % swap->stack_a->len;
	cost->rb = node_b->index;
	cost->total = cost->rra + cost->rb;
	cost->node_b = node_b;

	best_cost = get_cheapest_cost_struct(best_cost, cost);

	return (best_cost);
}

int	get_target_pos_in_a(t_stack *stack_a, int val_to_insert)
{
	t_swap_int	*current_a;
	t_swap_int	*min_node;

	current_a = stack_a->first;
	min_node = find_index(stack_a, stack_a->min);
	if (stack_a->len == 0)
		return (0);
	if (val_to_insert < stack_a->min || val_to_insert > stack_a->max)
	{
		if (val_to_insert > stack_a->max)
			return (get_node_index(stack_a, stack_a->last));
		return (get_node_index(stack_a, min_node));
	}
	while (current_a)
	{
		if (current_a->value < val_to_insert
			&& current_a->next->value > val_to_insert)
			return (get_node_index(stack_a, current_a) + 1);
		if (current_a->value == stack_a->max && val_to_insert < stack_a->min)
			return (get_node_index(stack_a, stack_a->last) + 1);
		current_a = current_a->next;
	}
	return (0);
}

void	push_back_to_a_optimized(t_swap *swap)
{
	t_swap_int	*current_b_node;
	t_cost		*cheapest_cost;
	t_cost		*current_cost;

	while (swap->stack_b->len > 0)
	{
		cheapest_cost = init_empty_cost();
		current_b_node = swap->stack_b->first;
		while (current_b_node)
		{
			current_cost = calculate_node_cost(swap, current_b_node);
			cheapest_cost = get_cost(cheapest_cost, current_cost);
			current_b_node = current_b_node->next;
		}
		execute_optimal_moves(swap, cheapest_cost);
	}
	final_sort_a_at_end(swap->stack_a);
}

void	execute_combined_rotations(t_swap *data, t_cost *optimal_cost)
{
	while (optimal_cost->rr > 0)
	{
		rr(data->stack_a, data->stack_b);
		optimal_cost->rr--;
	}
	while (optimal_cost->rrr > 0)
	{
		rrr(data->stack_a, data->stack_b);
		optimal_cost->rrr--;
	}
}

void	execute_individual_rotations_and_push(t_swap *data, t_cost *optimal_cost)
{
	while (optimal_cost->ra > 0)
	{
		ra(data->stack_a);
		optimal_cost->ra--;
	}
	while (optimal_cost->rb > 0)
	{
		rb(data->stack_b);
		optimal_cost->rb--;
	}
	while (optimal_cost->rra > 0)
	{
		rra(data->stack_a);
		optimal_cost->rra--;
	}
	while (optimal_cost->rrb > 0)
	{
		rrb(data->stack_b);
		optimal_cost->rrb--;
	}
	pa(data->stack_a, data->stack_b);
}

void	execute_optimal_moves(t_swap *data, t_cost *optimal_cost)
{
	execute_combined_rotations(data, optimal_cost);
	execute_individual_rotations_and_push(data, optimal_cost);
}