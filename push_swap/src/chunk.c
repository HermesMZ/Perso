/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:09:45 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 10:52:34 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_one_chunk(t_swap *swap, int chunk_min, int chunk_max)
{
	int		pivot;
	t_cost	*cheapest_cost;

	pivot = chunk_min + (chunk_max - chunk_min) / 2;
	while (1)
	{
		cheapest_cost = find_cheapest_element(swap, swap->stack_a,
				chunk_min, chunk_max);
		if (!cheapest_cost)
			break ;
		execute_optimal_moves(swap, cheapest_cost);
		if (swap->stack_b->first->index > pivot)
			ft_rotate(swap, swap->stack_b->first);
		free_cost_if_not_null(&cheapest_cost);
	}
}

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
