/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heads.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:59:49 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 00:49:58 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heads	*update_heads_for_merge(t_swap *swap, t_heads *heads)
{
	ft_printf("UPDATE\n");
	debug_print_split(heads);
	debug_print_stacks(swap);
	ft_printf("pushed / src : %d\n", heads->pushed->index);
	if (heads->remaining->stack == swap->stack_a)
	{
		heads->pushed = find_max_in_split(heads->pushed->stack->first, heads->push_count);
		heads->remaining = find_min_in_split(heads->remaining->stack->first,
				heads->remaining_count);
	}
	else
	{
		heads->pushed = find_min_in_split(heads->pushed->stack->first, heads->push_count);
		heads->remaining = find_max_in_split(heads->remaining->stack->first,
				heads->remaining_count);
	}
	ft_printf("END UPDATE\n");
	debug_print_split(heads);
	return (heads);
}

t_heads	*init_heads(int count, t_swap_int *pivot)
{
	t_heads		*heads;

	heads = malloc(sizeof(t_heads));
	if (!heads)
		return (NULL);
	heads->remaining = find_remaining_head_split(pivot);
	heads->pushed = find_pushed_head_split(pivot, count);
	heads->push_count = 0;
	heads->remaining_count = 0;
	return (heads);
}
