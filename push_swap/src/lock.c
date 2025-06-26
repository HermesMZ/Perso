/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:24:42 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 22:31:35 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	head_update(t_heads *heads)
{
	t_swap_int	*current;
	int			i;

	current = heads->pushed;
	i = 0;
	while (i < heads->push_count)
	{
		if (heads->pushed->locked)
			heads->pushed = heads->pushed->next;
		if (current->locked)
			heads->push_count--;
		current = current->next;
		i++;
	}
	i = 0;
	current = heads->remaining;
	while (i < heads->remaining_count)
	{
		if (heads->remaining->locked)
			heads->remaining = heads->remaining->next;
		if (current->locked)
			heads->remaining_count--;
		current = current->next;
		i++;
	}
}

void	lock_all(t_swap *swap, t_heads *heads)
{
	size_t		i;
	t_swap_int	*current;

	i = 0;
	current = swap->stack_a->first;
	while (i < swap->stack_a->len)
	{
		if (!current->locked && to_lock(current))
			current->locked = 1;
		current = current->next;
		i++;
	}
	head_update(heads);
}

// void	lock_all(t_stack *stack_a)
// {
// 	size_t		i;
// 	t_swap_int	*current;

// 	i = 0;
// 	current = stack_a->first;
// 	while (i < stack_a->len)
// 	{
// 		if (!current->locked && to_lock(current))
// 			current->locked = 1;
// 		current = current->next;
// 		i++;
// 	}
// }

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
	
// ft_printf("*************************** elem to push : %d\n", elem->value);
	if (!stack_a || !stack_a->first || !elem || stack_a->len == 0)
		return (NULL);
	i = 0;
	current = find_first_free(stack_a);
	target = find_index(stack_a, stack_a->max);
	while (i < stack_a->len)
	{
// // ft_printf("*************************** current : %d target : %d\n", current->value, target->value);

		if (current->locked && current->index > elem->index
			&& current->index < target->index)
			target = current;

		current = current->next;
		i++;
	}
// ft_printf("*************************** target : %d\n", target->value);

	return (target);
}
