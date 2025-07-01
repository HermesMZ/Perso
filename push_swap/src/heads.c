/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:59:49 by zoum              #+#    #+#             */
/*   Updated: 2025/07/01 15:24:20 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heads	*update_heads_for_merge(t_swap *swap, t_heads *heads)
{
	if (heads->remaining->stack == swap->stack_a)
	{
		heads->pushed = find_max_in_split(heads->pushed->stack->first,
				heads->push_count);
		heads->remaining = find_min_in_split(heads->remaining->stack->first,
				heads->remaining_count);
	}
	else
	{
		heads->pushed = find_min_in_split(heads->pushed->stack->first,
				heads->push_count);
		heads->remaining = find_max_in_split(heads->remaining->stack->first,
				heads->remaining_count);
	}
	return (heads);
}

t_heads	*init_heads(int count, t_swap_int *pivot)
{
	t_heads		*heads;

	heads = malloc(sizeof(t_heads));
	if (!heads)
		return (NULL);
	heads->push_count = 0;
	heads->remaining_count = 0;
	find_pushed_head_split(heads, pivot, count);
	find_remaining_head_split(heads, pivot, count);
	return (heads);
}
