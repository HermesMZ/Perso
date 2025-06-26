/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:24:42 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 16:40:58 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_lock(t_swap_int *elem)
{
	t_swap_int	*prev_locked;
	t_swap_int	*next_locked;

	prev_locked = elem;
	next_locked = elem;
	while (!prev_locked->locked)
		prev_locked = prev_locked->prev;
	while (!next_locked->locked)
		next_locked = next_locked->next;
	if (elem->index > prev_locked->index && elem->index < next_locked->index)
		return (1);
	else if (prev_locked->index > next_locked->index)
	{
		if (elem->index > prev_locked->index
			|| elem->index < next_locked->index)
			return (1);
	}
	return (0);
}

t_swap_int	*find_closest_inf_locked(t_stack *stack_a, t_swap_int *elem)
{
	t_swap_int	*target;
	t_swap_int	*current;
	size_t		i;

	if (!stack_a || !stack_a->first || !elem || stack_a->len == 0)
		return (NULL);
	i = 0;
	current = stack_a->first;
	target = find_index(stack_a, stack_a->max);
	while (i < stack_a->len)
	{
		if (current->locked && current->index < elem->index
			&& current->index > target->index)
			target = current;
		current = current->next;
		i++;
	}
	return (target);
}
