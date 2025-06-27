/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/06/27 17:46:53 by mzimeris         ###   ########.fr       */
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
// 	ft_printf("a-min %d, a-max %d\n", stack->min, stack->max);
// 	ft_printf("b-min %d, b-max %d\n", swap->stack_b->min, swap->stack_b->max);
// 	rotate_to(swap, find_max_in_split(stack->first, stack->len));
// 	ft_push(swap, swap->stack_b->first);
// 	while (swap->stack_b->len > 0)
// 	{
// 		rotate_to(swap, find_index(swap->stack_b, stack->first->index - 1));
// 		ft_push(swap, swap->stack_b->first);
// 		ft_printf("len b %d\n", swap->stack_b->len);
// 	debug_print_stacks(swap);
// 	}
// 	ft_printf("bouh\n");
// 	rotate_to(swap, find_index(stack, stack->min));
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
	ft_printf("count : %d\n", total_commands);
}

int	to_lock(t_swap_int *elem)
{
	t_swap_int	*prev_locked;
	t_swap_int	*next_locked;

	prev_locked = elem;
	next_locked = elem;
	while (!prev_locked->locked)
		prev_locked = prev_locked->prev;
	while (!next_locked->locked)
		next_locked = next_locked->next;
	if (elem->index > prev_locked->index
		&& elem->index < next_locked->index)
		return (1);
	else if (prev_locked->index > next_locked->index)
	{
		if (elem->index > prev_locked->index
			|| elem->index < next_locked->index)
			return (1);
	}
	return (0);
}

void	lock_all(t_stack *stack)
{
	size_t		i;
	t_swap_int	*current;

	i = 0;
	current = stack->first;
	while (i < stack->len)
	{
		if (!current->locked && to_lock(current))
			current->locked = 1;
		current = current->next;
		i++;
	}
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
	debug_print_stacks(swap);
	find_median(swap->stack_a->first, len)->locked = 1;
	size_t i = 0;
	while (i < len )
	{
		if (to_lock(swap->stack_a->first))
			swap->stack_a->first->locked = 1;
		if (swap->stack_a->first->locked)
			ft_rotate(swap, swap->stack_a->first);
		else
			ft_push(swap, swap->stack_a->first);
		debug_print_stacks(swap);
		ft_printf("%d", i);
		i++;
	}
	debug_print_stacks(swap);
	ft_printf("fini le premier tri\n");
	
	// quick_sort_stack(swap, stack->first, len);
	push_back_to_a_optimized(swap);
	
	// final_merge(swap);
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
	// printf("commands done : %d\n", ft_lstsize(swap->move) - 1);
	debug_print_stacks(swap);
	// print_moves(swap->move);
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
	// while ((is_sorted(stack->length, stack->first) != 1)
	// 		&& swap->stack_b->length != 0)
		// push_swap(swap);
	// ft_printf("sorted %d\n", is_circularly_sorted(stack));
	