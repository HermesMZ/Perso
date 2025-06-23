/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/06/23 13:41:18 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make && clear && valgrind --track-origins=yes ./push_swap 1 0 9 5 3 4 6 7 2 8 > test.txt 

void final_merge(t_swap *swap)
{
	ft_printf("before final rotate\n");
	debug_print_stacks(swap);

	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
	rotate_to(swap, find_index(swap->stack_b, swap->stack_b->max));
	ft_printf("after final rotate\n");
	debug_print_stacks(swap);
	int first_a;
	int first_b;

	while (swap->stack_b->len)
	{
		ft_printf("a %d b %d\n",first_a, first_b);
		debug_print_stacks(swap);
		first_a = swap->stack_a->first->index;
		first_b = swap->stack_b->first->index;
		if (first_b > swap->stack_a->max || (first_b < first_a && first_b > swap->stack_a->last->index))
			ft_push(swap, swap->stack_b->first);
		else
			ft_rotate(swap, find_index(swap->stack_a, first_b + 1));
			
	}
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
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

	// ft_swap(swap, swap->stack_a->first);
	// hard_sort_3(swap, swap->stack_a->first);
	// quick_sort_stack(swap, swap->stack_a->first, len);
	quick_sort_stack(swap, swap->stack_a->first, len);
	ft_printf("============== CIRC SORTED ==============\n");
	final_merge(swap);
	debug_print_stacks(swap);


	free_all(swap);
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
	