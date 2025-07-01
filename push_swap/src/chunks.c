/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:09:45 by zoum              #+#    #+#             */
/*   Updated: 2025/07/01 22:04:50 by zoum             ###   ########.fr       */
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

void	push_one_chunk(t_swap *swap, int chunk_min, int chunk_max)
{
	t_swap_int	*current;
	int			rotations;

	while (has_chunk(swap->stack_a, chunk_min, chunk_max))
	{
		current = swap->stack_a->first;
		rotations = 0;
		while (!(current->index >= chunk_min && current->index <= chunk_max))
		{
			current = current->next;
			rotations++;
		}
		rotate_n_times(swap, rotations);
		ft_push(swap, current);
	}
	return ;
}

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
