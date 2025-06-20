/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 23:49:09 by zoum              #+#    #+#             */
/*   Updated: 2025/06/20 04:40:29 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_circularly_sorted(t_stack *stack)
{
	t_swap_int	*current;
	size_t		i;
	int			asc_breaks;
	int			desc_breaks;

	if (!stack || stack->len <= 1)
		return (1);
	current = stack->first;
	asc_breaks = 0;
	desc_breaks = 0;
	i = 0;
	while (i < stack->len)
	{
		if (current->value > current->next->value)
			asc_breaks++;
		if (current->value < current->next->value)
			desc_breaks++;
		current = current->next;
		i++;
	}
	if (asc_breaks == 0 || asc_breaks == 1)
		return (1);
	else if (desc_breaks == 0 || desc_breaks == 1)
		return (-1);
	return (0);
}

// -1 decrease
// 1 increase
// 0 not sorted
int	is_sorted(size_t len, t_swap_int *elem)
{
	t_swap_int	*current;
	int			order;
	size_t		i;

	if (!elem || len <= 1)
		return (1);
	current = elem;
	order = current->value - current->next->value;
	i = 0;
	while (i < len - 1 && order)
	{
		if (current->value > current->next->value && order < 0)
			return (0);
		if (current->value < current->next->value && order > 0)
			return (0);
		current = current->next;
		i++;
	}
	return (-order);
}
// simplifiable en comparant par rapport a len / 2

int	r_or_rr(t_swap_int *target)
{
	int			r_count;
	int			rr_count;
	t_swap_int	*current;

	if (!target || !target->stack || target->stack->len == 0)
		return (0);
	r_count = 0;
	current = target->stack->first;
	while (current && current != target)
	{
		current = current->next;
		r_count++;
		if (r_count > (int)target->stack->len)
			return (-1);
	}
	if (r_count == 0)
		rr_count = 0;
	else
		rr_count = target->stack->len - r_count;
	if (r_count <= rr_count)
		return (r_count);
	else
		return (-rr_count);
}

void	rotate_to(t_swap *swap, t_swap_int *elem)
{
	int	start;
	
	if (!swap || !elem || elem == elem->stack->first)
		return ;
	start = r_or_rr(elem);
	{
		while (elem->stack->first != elem)
		{
			if (start < 0)
				ft_reverse_rotate(swap, elem);
			else if (start > 0)
				ft_rotate(swap, elem);
		}
	}
}

// void	first_cleaning(t_swap *swap)
// {
// 	t_swap_int	*current;

// 	ft_printf("best_start %d\n", swap->best_start->value);
// 	// rotate_to_start(swap);
// 	debug_print_stacks(swap);
// 	current = swap->stack_a->first;
// 	while (!is_circularly_sorted(swap->stack_a))
// 	{
// 		if (current->value > current->next->value
// 			&& current->next->value > current->prev->value)
// 			swap_a(swap);
// 		else if (current->value > current->prev->value
// 			|| current == swap->best_start)
// 		{
// 			rotate_a(swap);
// 			if (swap->stack_b->len > 0
// 				&& swap->stack_b->first->value < current->value
// 				&& swap->stack_b->first->value > current->prev->value)
// 				push_a(swap);
// 		}
// 		else
// 			push_b(swap);
// 		current = swap->stack_a->first;
// 	}
// 	debug_print_stacks(swap);
// }
