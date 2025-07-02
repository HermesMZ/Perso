/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:59:46 by zoum              #+#    #+#             */
/*   Updated: 2025/07/02 16:01:13 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
	t_swap_int	*current;
	size_t		i;

	i = 0;
	current = stack->first;
	while (i < stack->len)
	{
		if (current->index >= chunk_min && current->index <= chunk_max)
			return (1);
		current = current->next;
		i++;
	}
	return (0);
}

void	rotate_n_times(t_swap *swap, int n)
{
	while (n > 0)
	{
		ft_rotate(swap, swap->stack_a->first);
		n--;
	}
}

t_swap_int	*find_next_chunk_elem(t_swap_int *current, int chunk_min,
	int chunk_max)
{
	t_swap_int	*next;
	t_swap_int	*prev;
	size_t		i;

	if (!current)
		return (NULL);
	i = 0;
	next = current->next;
	prev = current->prev;
	if (current->index >= chunk_min && current->index <= chunk_max)
		return (current);
	while (i < current->stack->len / 2 + 1)
	{
		if (next->index >= chunk_min && next->index <= chunk_max)
			return (next);
		if (prev->index >= chunk_min && prev->index <= chunk_max)
			return (prev);
		next = next->next;
		prev = prev->prev;
		i++;
	}
	return (NULL);
}
