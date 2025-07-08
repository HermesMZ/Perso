/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/08 12:11:13 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(t_list *move)
{
	t_list	*current;
	int		total_commands;

	total_commands = 0;
	current = move;
	current = current->next;
	while (current)
	{
		ft_printf("%s", current->content);
		total_commands++;
		current = current->next;
	}
}

int	calculate_chunk_count(size_t len)
{
	if (len <= 100)
		return (2);
	else if (len <= 500)
		return (5);
	else
		return (len / 25);
}

void	sort(t_swap *swap)
{
	int			pivot;

	pivot = swap->stack_a->min + (swap->stack_a->max - swap->stack_a->min) / 2;
	while (swap->stack_a->len > 3)
	{
		if (swap->stack_a->first->index == swap->max)
			ft_rotate(swap, swap->stack_a->first);
		ft_push(swap, swap->stack_a->first);
		if (swap->stack_b->first->index > pivot)
			ft_rotate(swap, swap->stack_b->first);
	}
	hard_sort(swap, swap->stack_a->first, swap->stack_a->len);
	push_back_to_a_optimized(swap);
}

int	main(int argc, char *argv[])
{
	size_t		len;
	t_swap		*swap;

	swap = NULL;
	if (argc < 2)
		return (0);
	len = argc - 1;
	swap = swap_init(swap, argv, len);
	push_chunks(swap, calculate_chunk_count(len));
	sort(swap);
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
	print_moves(swap->move);
	free_all(swap);
	return (0);
}
