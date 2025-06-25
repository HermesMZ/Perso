/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_dlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:54:18 by zoum              #+#    #+#             */
/*   Updated: 2025/06/24 10:35:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_init(void)
{
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->first = NULL;
	new_stack->last = NULL;
	new_stack->len = 0;
	new_stack->min = 0;
	new_stack->max = 0;
	return (new_stack);
}

t_swap_int	*new_swap_int(int value)
{
	t_swap_int	*new_elem;

	new_elem = malloc(sizeof(t_swap_int));
	if (!new_elem)
		return (NULL);
	new_elem->value = value;
	new_elem->index = 0;
	new_elem->stack = NULL;
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->locked = 0;
	return (new_elem);
}

void	ft_stack_add_back(t_stack *stack, int value)
{
	t_swap_int	*new_elem;

	if (!stack)
		return ;
	new_elem = new_swap_int(value);
	if (!new_elem)
		return ;
	if (stack->len == 0)
	{
		stack->first = new_elem;
		stack->last = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		stack->last->next = new_elem;
		new_elem->prev = stack->last;
		stack->last = new_elem;
		new_elem->next = stack->first;
		stack->first->prev = new_elem;
	}
	new_elem->stack = stack;
	stack->len++;
}

void	ft_stack_add_front(t_stack *stack, int value)
{
	t_swap_int	*new_elem;

	if (!stack)
		return ;
	new_elem = malloc(sizeof(t_elem));
	if (!new_elem)
		return ;
	new_elem->value = value;
	if (stack->len == 0)
	{
		stack->first = new_elem;
		stack->last = new_elem;
		new_elem->next = new_elem;
		new_elem->prev = new_elem;
	}
	else
	{
		stack->first->prev = new_elem;
		new_elem->next = stack->first;
		stack->first = new_elem;
		new_elem->prev = stack->last;
		stack->last->next = new_elem;
	}
	stack->len++;
}
