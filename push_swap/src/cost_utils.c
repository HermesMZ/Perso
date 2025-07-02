/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:55:44 by zoum              #+#    #+#             */
/*   Updated: 2025/07/02 23:24:44 by zoum             ###   ########.fr       */
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
	cost->elem = NULL;
	return (cost);
}

static t_cost	*cost_raw_rotations(t_swap_int *elem_a, t_swap_int *elem_b)
{
	t_cost	*cost;

	cost = init_empty_cost();
	if (!cost)
		return (NULL);
	if (elem_a)
		cost->ra = r_or_rr(elem_a);
	if (elem_b)
		cost->rb = r_or_rr(elem_b);

	cost->elem = elem_a;
	return (cost);
}

t_cost	*calculate_cost_for_a_to_b(t_swap *swap, t_swap_int *elem_a)
{
	t_cost		*cost;
	t_swap_int	*target_b;

	target_b = get_target(swap, elem_a);
	cost = cost_raw_rotations(elem_a, target_b);
	if (!cost)
		return (NULL);
	if (cost->ra == 0)
		cost->rb = 0;
	if (cost->ra > 0 && cost->rb > 0 && cost->ra > cost->rb)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	else if (cost->ra < 0 && cost->rb < 0 && cost->ra < cost->rb)
	{
		cost->rr = ft_max(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->rb = 0;
	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr) + 1;
	cost->elem = elem_a;
	return (cost);
}

t_cost	*calculate_cost_for_b_to_a(t_swap *swap, t_swap_int *elem_b)
{
	t_cost		*cost;
	t_swap_int	*target_a;

	target_a = get_target(swap, elem_b);
	cost = cost_raw_rotations(target_a, elem_b);
	if (!cost)
		return (NULL);
	cost->rr = 0;
	if (cost->ra > 0 && cost->rb > 0)
	{
		cost->rr = ft_min(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	else if (cost->ra < 0 && cost->rb < 0)
	{
		cost->rr = ft_max(cost->ra, cost->rb);
		cost->ra -= cost->rr;
		cost->rb -= cost->rr;
	}
	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr) + 1;
	cost->elem = elem_b;
	return (cost);
}

// t_cost	*calculate_node_cost(t_swap *swap, t_swap_int *elem_a,
// 	t_swap_int *elem_b)
// {
// 	t_cost		*cost;

// 	cost = init_empty_cost();
// 	if (!cost)
// 		return (NULL);
// 	cost->ra = r_or_rr(elem_a);
// 	cost->rb = r_or_rr(elem_b);
// 	if (cost->ra > 0 && cost->rb > 0)
// 	{
// 		cost->rr = ft_min(cost->ra, cost->rb);
// 		cost->ra -= cost->rr;
// 		cost->rb -= cost->rr;
// 	}
// 	if (cost->ra < 0 && cost->rb < 0)
// 	{
// 		cost->rr = ft_max(cost->ra, cost->rb);
// 		cost->ra -= cost->rr;
// 		cost->rb -= cost->rr;
// 	}
// 	cost->total = ft_abs(cost->ra) + ft_abs(cost->rb) + ft_abs(cost->rr);
// 	cost->elem = elem_b;
// 	return (cost);
// }

