/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:24:42 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 12:42:15 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lock_all(t_swap *swap)
{
	size_t		i;
	t_swap_int	*current;

	i = 0;
	current = swap->stack_a->first;
	while (i < swap->stack_a->len)
	{
		if (!current->locked && to_lock(swap, current))
			current->locked = 1;
		current = current->next;
		i++;
	}
}

int	to_lock(t_swap *swap, t_swap_int *elem)
{
	t_swap_int	*prev_locked;
	t_swap_int	*next_locked;

	prev_locked = elem;
	next_locked = elem;
	if (elem->stack == swap->stack_a)
	{
		while (!prev_locked->locked)
			prev_locked = prev_locked->prev;
		while (!next_locked->locked)
			next_locked = next_locked->next;
		if (elem->index > prev_locked->index
			&& elem->index < next_locked->index)
			return (1);
		else if (prev_locked->index > next_locked->index)
		{
			if (elem->index > prev_locked->index
				|| elem->index < next_locked->index)
				return (1);
		}
	}
	return (0);
}
