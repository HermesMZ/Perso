/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:38:53 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 22:03:00 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_heads	*split_with_pivot(t_swap *swap, t_swap_int *pivot,
	t_heads *heads,	int count)
{
	t_swap_int	*current;
	int			i;

	if (count <= 0)
		return (NULL);
	current = pivot->stack->first;
	ft_printf("before split\n");
	debug_print_stacks(swap);
	debug_print_split(heads);
	ft_printf("pivot %d\n", pivot->value);
	ft_printf("closest locked %d\n", find_closest_inf_locked(swap->stack_a, current)->value);
	if (pivot->stack == swap->stack_b)
	{
		ft_printf("pushed head %d\n", find_pushed_head_split(pivot, count)->value);
		rotate_to(swap, find_closest_inf_locked(swap->stack_a, find_pushed_head_split(pivot, count)));
		ft_printf("after rotate\n");
		debug_print_stacks(swap);
	}
	i = 0;
	while (i < count)
	{
		if (current->index > pivot->index && !current->locked)
		{
			ft_push(swap, current);
			heads->push_count++;
		}
		else
		{
			ft_rotate(swap, current);
			if (!current->locked)
				heads->remaining_count++;
		}
		current = pivot->stack->first;
		if (!current->locked)
			i++;
	}
	lock_all(swap, heads);
	ft_printf("after split\n");
	debug_print_stacks(swap);
	debug_print_split(heads);
	if (heads->push_count == 0 && heads->remaining_count <= 3)
	{
		ft_printf("************************** anticipated merge ******************** \n");
		hard_sort(swap, heads->remaining, heads->remaining_count);
		anticipate_merge(swap, &heads);
	}
	head_update(heads);

	ft_printf("after split\n");
	debug_print_stacks(swap);
	debug_print_split(heads);

	return (heads);
}

t_swap_int	*recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_heads		*heads;
	t_swap_int	*pivot;
	t_swap_int	*result;

	if (count <= 0)
		return (NULL);
	pivot = find_median(first, count);
	heads = init_heads(count, pivot);
	split_with_pivot(swap, pivot, heads, count);
	if (heads->push_count > 2)
		quick_sort_stack(swap, heads->pushed, heads->push_count);
	else
		hard_sort(swap, heads->pushed, heads->push_count);
	if (heads->remaining_count > 2)
		quick_sort_stack(swap, heads->remaining, heads->remaining_count);
	else
		hard_sort(swap, heads->remaining, heads->remaining_count);
	update_heads_for_merge(swap, heads);
	merge_stacks_count(swap, &heads);
	heads->remaining = heads->remaining->stack->first;
	if (swap->stack_b->len == 0)
		result = NULL;
	else
		result = heads->remaining;
	free(heads);
	return (result);
}

	// if (swap->stack_a->len <= 3)
	// if (heads->push_count <= 3 && heads->remaining_count <= 3)