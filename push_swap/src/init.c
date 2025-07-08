/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:46:38 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 15:50:18 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack_a(t_swap *swap, char *argv[], size_t len)
{
	size_t	i;

	i = 1;
	swap->stack_a = ft_stack_init();
	if (!swap->stack_a)
		return ;
	while (i <= len)
		ft_stack_add_back(swap->stack_a, ft_atoi(argv[i++]));
	swap->stack_a->first->prev = swap->stack_a->last;
	swap->stack_a->last->next = swap->stack_a->first;
}

t_swap	*swap_init(t_swap *swap, char *argv[], size_t len)
{
	t_list	*move;

	move = ft_lstnew(ft_strdup("start"));
	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (NULL);
	init_stack_a(swap, argv, len);
	swap->stack_b = ft_stack_init();
	if (!swap->stack_a || !swap->stack_b)
		return (NULL);
	swap->stack_b->max = 0;
	swap->stack_b->min = 0;
	fill_index(swap->stack_a);
	set_min_max(swap->stack_a);
	swap->min = swap->stack_a->min;
	swap->max = swap->stack_a->max;
	find_index(swap->stack_a, swap->stack_a->min)->locked = 1;
	find_index(swap->stack_a, swap->stack_a->max)->locked = 1;
	swap->move = move;
	return (swap);
}
