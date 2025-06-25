/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:29:43 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 01:01:42 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	merge_to_stack(t_swap *swap, t_heads **heads, t_stack *from, t_stack *to)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	debug_print_split(*heads);
	while (to->first->index < from->first->index && j < (*heads)->remaining_count && to ==swap->stack_a)
	{
		ft_rotate(swap, to->first);
		j++;
	}
	debug_print_stacks(swap);
	while (i < (*heads)->push_count)
	{
		ft_push(swap, from->first);
		i++;
	}
	ft_printf("rem : %d\n", (*heads)->remaining->index);
	if (to == swap->stack_b)
		(*heads)->remaining = (*heads)->remaining->stack->first;
	else
		rotate_to(swap, (*heads)->remaining);
}


void	merge_stacks_count(t_swap *swap, t_heads **heads)
{
	ft_printf("DEBUT DU MERGE\n");
	debug_print_split(*heads);
	
	debug_print_stacks(swap);
	if ((*heads)->pushed->stack == swap->stack_b)
		merge_to_stack(swap, heads, swap->stack_b, swap->stack_a);
	else
		merge_to_stack(swap, heads, swap->stack_a, swap->stack_b);
	ft_printf("FIN DU MERGE\n");
	debug_print_stacks(swap);
}
