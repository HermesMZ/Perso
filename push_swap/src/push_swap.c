/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 17:38:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/01 15:24:57 by zoum             ###   ########.fr       */
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

void	sort(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;

	pivot = find_median(first, count);
	i = 0;
	pivot->locked = 1;
	current = pivot->stack->first;
	while (swap->stack_a->len > 3)
	{
		if (!current->locked)
		{
			ft_push(swap, current);
			i++;
		}
		else
			ft_rotate(swap, current);
		current = swap->stack_a->first;
	}
	hard_sort(swap, swap->stack_a->first, 3);
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
	quick_sort_stack(swap, swap->stack_a->first, len);
	sort(swap, swap->stack_a->first, swap->stack_a->len);
	rotate_to(swap, find_index(swap->stack_a, swap->stack_a->min));
	debug_print_stacks(swap);
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
