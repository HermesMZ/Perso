/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:38:53 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 00:57:19 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_heads	*split_with_pivot(t_swap *swap, t_swap_int *pivot,
	t_heads *heads,	int count)
{
	t_swap_int	*current;
	int			i;
	
	ft_printf("DEBUT DU SPLIT\n");
	debug_print_stacks(swap);
	current = pivot->stack->first;
	i = 0;
	while (i < count)
	{
		if (current->index > pivot->index)
		{
			ft_push(swap, current);
			heads->push_count++;
		}
		else
		{
			ft_rotate(swap, current);
			heads->remaining_count++;
		}
		current = pivot->stack->first;
		i++;
	}
	debug_print_stacks(swap);
	ft_printf("FIN DU SPLIT\n");
	debug_print_split(heads);
	return (heads);
}

// static void	hard_sort_stacks(t_swap *swap, t_heads *heads)
// {
// 	ft_printf("DEBUT DU SORT\n");
// 	debug_print_split(heads);
// 	// debug_print_stacks(swap);
// 	hard_sort(swap, heads->pushed, heads->push_count);
// 	ft_printf("rotate\n");
// 	debug_print_split(heads);

// 	rotate_to(swap, heads->remaining);
// 	hard_sort(swap, heads->remaining, heads->remaining_count);
// 	ft_printf("FIN DU SORT\n");
// 	debug_print_stacks(swap);
// }

t_swap_int	*recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_heads		*heads;
	t_swap_int	*pivot;
	t_swap_int	*result;

	pivot = find_median(first, count);
	ft_printf("pivot %d\n", pivot->index);
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