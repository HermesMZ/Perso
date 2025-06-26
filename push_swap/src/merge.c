/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 19:29:43 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 22:14:11 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	anticipate_merge(t_swap *swap, t_heads **heads)
{
	int	i;

	i = 0;
	while (i < (*heads)->remaining_count)
	{
		ft_push(swap, swap->stack_b->first);
		i++;
	}
	lock_all(swap, *heads);
	head_update(*heads);
}

void	merge_to_stack(t_swap *swap, t_heads **heads, t_stack *from, t_stack *to)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to == swap->stack_a)
		rotate_to(swap, find_closest_inf_locked(to, from->first));
	ft_printf("================ A\n");
	debug_print_stacks(swap);
	while (to->first->index < from->first->index && j < (*heads)->remaining_count && to ==swap->stack_a)
	{
		ft_rotate(swap, to->first);
		j++;
	}
	ft_printf("================ B\n");
	debug_print_stacks(swap);
	while (i < (*heads)->push_count && !from->first->locked)
	{
		ft_push(swap, from->first);
		i++;
	}
	ft_printf("================ C\n");
	debug_print_stacks(swap);

	if (to == swap->stack_b)
		(*heads)->remaining = (*heads)->remaining->stack->first;
	else
		rotate_to(swap, (*heads)->remaining);
	head_update(*heads);
}


void	merge_stacks_count(t_swap *swap, t_heads **heads)
{
	head_update(*heads);
	if ((*heads)->remaining_count <= 0 || (*heads)->push_count <= 0)
		return ;
	ft_printf("DEBUT DU MERGE\n");
	debug_print_stacks(swap);
	debug_print_split(*heads);
	if ((*heads)->pushed->stack == swap->stack_b)
		merge_to_stack(swap, heads, swap->stack_b, swap->stack_a);
	else
		merge_to_stack(swap, heads, swap->stack_a, swap->stack_b);
	ft_printf("FIN DU MERGE\n");
	debug_print_stacks(swap);
	debug_print_split(*heads);

}
