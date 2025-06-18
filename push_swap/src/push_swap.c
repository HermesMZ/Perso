/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/06/18 20:54:45 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	size_t		len;
	t_swap		*swap;

	swap = NULL;
	if (argc < 2)
		return (0);
	len = argc - 1;
	swap = swap_init(swap, argv, len);
	// ft_swap(swap, swap->stack_a->first);
	// hard_sort_3(swap, swap->stack_a->first);
	quick_sort_stack(swap, swap->stack_a->first, len);
	debug_print_stacks(swap);

	return (0);
}
// stocker les instructions avant de les imprimer pour faire du tri
// supprimer les ra et rra qui se suivent
// remplacer les ra + rb ou rra +rrb par rr / rrr
// supprimer les pa pb qui se suivent ? weird
// check malloc
// hard 5
// optimiser les rotations au moment du split en fonction du nombre de push ?

	// first_cleaning(swap);
	// algo à implémenter
	// while ((is_sorted(swap->stack_a->length, swap->stack_a->first) != 1)
	// 		&& swap->stack_b->length != 0)
		// push_swap(swap);
	// ft_printf("sorted %d\n", is_circularly_sorted(swap->stack_a));
	