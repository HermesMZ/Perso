/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/01 22:18:28 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// make && clear && valgrind --track-origins=yes ./push_swap 1 0 9 5 3 4 6 7 2 8 > test.txt 

// begin when the last split has been done
// void final_merge(t_swap *swap)
// {
// 	ft_printf("before final rotate\n");
// 	debug_print_stacks(swap);
// 	ft_printf("min %d, max %d\n", swap->min, swap->max);
// 	ft_printf("a-min %d, a-max %d\n", swap->stack_a->min, swap->stack_a->max);
// 	ft_printf("b-min %d, b-max %d\n", swap->stack_b->min, swap->stack_b->max);
// 	rotate_to(swap, find_max_in_split(swap->stack_a->first, swap->stack_a->len));
// 	ft_push(swap, swap->stack_b->first);
// 	while (swap->stack_b->len > 0)
// 	{
// 		rotate_to(swap, find_index(swap->stack_b, swap->stack_a->first->index - 1));
// 		ft_push(swap, swap->stack_b->first);
// 		ft_printf("len b %d\n", swap->stack_b->len);
// 	debug_print_stacks(swap);
// 	}
// 	ft_printf("bouh\n");
// 	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
// 	debug_print_stacks(swap);
// }
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
	// ft_printf("count : %d\n", total_commands);
}

int	calculate_chunk_count(size_t len)
{
	if (len <= 100)
		return (5);
	else if (len <= 500)
		return (len / 30);
	else
		return (len / 25);
}

void	sort(t_swap *swap)
{
	while (swap->stack_a->len > 2)
		ft_push(swap, swap->stack_a->first);
	// ft_printf("empty a\n");
	// debug_print_stacks(swap);
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
	debug_print_stacks(swap);
	ft_printf("end sort\n");
	print_moves(swap->move);
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
	