/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:25:09 by zoum              #+#    #+#             */
/*   Updated: 2025/07/01 01:41:09 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_swap_int	*find_first_free(t_stack *stack_a)
{
	size_t		i;
	t_swap_int	*current;

	current = stack_a->first;
	i = 0;
	while (i < stack_a->len)
	{
		if (!current->locked)
			return (current);
		current = current->next;
		i++;
	}
	return (NULL);
}

t_swap_int	*find_min_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*min;
	int			i;
	t_swap_int	*current;

	min = elem;
	current = elem;
	i = 0;
	while (i < count)
	{
		if (current->index < min->index && !current->locked)
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}

t_swap_int	*find_max_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*max;
	int			i;
	t_swap_int	*current;

	current = elem;
	max = elem;
	i = 0;
	while (i < count)
	{
		if (current->index > max->index && !current->locked)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

void	find_pushed_head_split(t_heads *heads, t_swap_int *pivot, int count)
{
	t_swap_int	*current;
	int			i;

	i = 0;
	current = pivot->stack->first;
	heads->pushed = current;
	while (i < count)
	{
		if (current->value > pivot->value && !current->locked)
		{
			heads->pushed = current;
			heads->push_count++;
		}
		current = current->next;
		i++;
	}
}

void	find_remaining_head_split(t_heads *heads, t_swap_int *pivot, int count)
{
	t_swap_int	*current;
	int			i;
	int			j;

	i = 0;
	current = pivot->stack->first;
	heads->remaining_count = 0;
	while (i < count && current->index > pivot->index && !current->locked)
	{
		current = current->next;
		i++;
	}
	heads->remaining = current;

	j = 0;
	while (i + j < count)
	{
		if (current->value <= pivot->value && !current->locked)
			heads->remaining_count++;

		current = current->next;
		j++;
	}
}
