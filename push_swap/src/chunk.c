/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 20:09:45 by zoum              #+#    #+#             */
/*   Updated: 2025/07/02 23:17:41 by zoum             ###   ########.fr       */
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

// static void	process_chunk_element(t_swap *swap, t_swap_int *elem, int pivot)
// {
// 	ft_push(swap, elem);
// 	if (elem->index >= pivot)
// 		ft_rotate(swap, elem);
// }

// static void	rotate_for_chunk_element(t_swap *swap, t_swap_int *elem)
// {
// 	int	rotations;

// 	rotations = r_or_rr(elem);
// 	if (rotations > 0)
// 	{
// 		while (rotations--)
// 			ft_rotate(swap, swap->stack_a->first);
// 	}
// 	else
// 	{
// 		while (rotations++)
// 			ft_reverse_rotate(swap, swap->stack_a->first);
// 	}
// }

// void	push_one_chunk(t_swap *swap, int chunk_min, int chunk_max)
// {
// 	int			pivot;
// 	t_swap_int	*target_elem;

// 	pivot = chunk_min + (chunk_max - chunk_min) / 2;
// 	while (has_chunk(swap->stack_a, chunk_min, chunk_max))
// 	{
// 		target_elem = find_next_chunk_elem(swap->stack_a->first,
// 				chunk_min, chunk_max);
// 		if (!target_elem)
// 			break ;
// 		rotate_for_chunk_element(swap, target_elem);
// 		process_chunk_element(swap, swap->stack_a->first, pivot);
// 	}
// }


