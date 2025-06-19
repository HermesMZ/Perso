/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/19 02:11:56 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot,
	t_swap_int **current, int *push_count)
{
	t_swap_int	*last_pushed;
	t_swap_int	*next;
	
	if (!*current)
		return (NULL);
	next = (*current)->next;
	if (next->stack == swap->stack_a)
		last_pushed = swap->stack_b->first;
	else
		last_pushed = swap->stack_a->first;
	ft_printf("current index %d pivot %d \n", (*current)->index, pivot->index);
	if ((*current)->index >= pivot->index)
	{
		ft_push(swap, *current);
		last_pushed = *current;
		(*push_count)++;
	}
	else
		ft_rotate(swap, (*current));
	*current = next;
	debug_print_stacks(swap);
	
	return (last_pushed);
}

// static void	stack_merge(t_swap *swap, t_elem *elem, int count)
// {
	
// }

void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	t_swap_int	*last_pushed;
	int			i;
	int			push_count;

	if (!first || count <= 1)
		return ;
	rotate_to(swap, first);
	if (count > 2)
	{
		pivot = find_median(first, count);
		current = first;
		push_count = 0;
		last_pushed = NULL;
		i = 0;
		while (i < count)
		{
			// problème quand rien n'est push : solution temporaire trop de variable
			last_pushed = stack_split(swap, pivot, &current, &push_count);
			i++;
		}
		if (push_count > 0)
			quick_sort_stack(swap, last_pushed, push_count);
		if (count - push_count > 0)
			quick_sort_stack(swap, current, count - push_count);
	}
	else
		hard_sort(swap, first, count);

}
