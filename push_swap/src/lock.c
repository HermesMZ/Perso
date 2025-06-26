/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:24:42 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 15:25:07 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	to_lock(t_stack *stack_a, t_swap_int *elem)
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
	return (0);
}