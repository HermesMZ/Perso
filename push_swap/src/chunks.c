/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:09:45 by zoum              #+#    #+#             */
/*   Updated: 2025/07/02 00:46:07 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chunks(t_swap *swap, int nb_chunks)
{
	int			chunk_size;
	int			chunk_min;
	int			chunk_max;
	int			i;

	chunk_size = swap->stack_a->len / nb_chunks;
	i = 0;
	while (i < nb_chunks)
	{
		chunk_min = i * chunk_size;
		if (i == nb_chunks - 1)
			chunk_max = swap->stack_a->len - 1;
		else
			chunk_max = (i + 1) * chunk_size - 1;
		push_one_chunk(swap, chunk_min, chunk_max);
		i++;
	}
}

// helper for push_one_chunk
static void	process_chunk_element(t_swap *swap, t_swap_int *elem, int pivot)
{
	if (to_lock(swap, elem))
	{
		elem->locked = 1;
	}
	else
	{
		ft_push(swap, elem);
		if (elem->index < pivot)
			ft_rotate(swap, elem);
	}
}

// helper for push_one_chunk
static void	rotate_for_chunk_element(t_swap *swap, t_swap_int *elem)
{
	int	rotations;

	rotations = r_or_rr(elem);
	if (rotations > 0)
	{
		while (rotations--)
			ft_rotate(swap, swap->stack_a->first);
	}
	else
	{
		while (rotations++)
			ft_reverse_rotate(swap, swap->stack_a->first);
	}
}

void	push_one_chunk(t_swap *swap, int chunk_min, int chunk_max)
{
	int			pivot;
	t_swap_int	*target_elem;

	pivot = chunk_min + (chunk_max - chunk_min) / 2;
	while (has_chunk(swap->stack_a, chunk_min, chunk_max))
	{
		target_elem = find_next_chunk_elem(swap->stack_a->first,
				chunk_min, chunk_max);
		if (!target_elem)
			break ;
		rotate_for_chunk_element(swap, target_elem);
		process_chunk_element(swap, swap->stack_a->first, pivot);
	}
}

// void	push_one_chunk(t_swap *swap, int chunk_min, int chunk_max)
// {
// 	rotate_to(swap, find_next_chunk_elem(swap->stack_a->first,
// 			chunk_min, chunk_max));
// 	while (has_chunk(swap->stack_a, chunk_min, chunk_max))
// 	{
// 		rotate_to(swap, find_next_chunk_elem(swap->stack_a->first,
// 				chunk_min, chunk_max));
// 		ft_push(swap, swap->stack_a->first);
// 	}
// 	return ;
// }

int	has_chunk(t_stack *stack, int chunk_min, int chunk_max)
{
	t_swap_int	*current;
	size_t		i;

	i = 0;
	current = stack->first;
	while (i < stack->len)
	{
		if (current->index >= chunk_min && current->index <= chunk_max
			&& !current->locked)
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
	if (current->index >= chunk_min && current->index <= chunk_max
		&& !current->locked)
		return (current);
	while (i < current->stack->len / 2 + 1)
	{
		if (next->index >= chunk_min && next->index <= chunk_max
			&& !next->locked)
			return (next);
		if (prev->index >= chunk_min && prev->index <= chunk_max
			&& !prev->locked)
			return (prev);
		next = next->next;
		prev = prev->prev;
		i++;
	}
	return (NULL);
}
