/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:11:53 by mzimeris          #+#    #+#             */
/*   Updated: 2025/06/18 22:33:40 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_del_swapint(t_swap_int *p_elem, void (*del)(void*))
{
	if (!p_elem || !del)
		return ;
	del((void *)(long long)p_elem->value);
	free(p_elem);
}

static void	ft_stack_clear(t_stack **p_lst, void (*del)(void*))
{
	t_swap_int	*current;
	t_swap_int	*next_elem;

	if (!p_lst || !*p_lst || !del)
		return ;
	if ((*p_lst)->len == 0)
	{
		free(*p_lst);
		*p_lst = NULL;
		return ;
	}
	(*p_lst)->last->next = NULL;
	current = (*p_lst)->first;
	while (current)
	{
		next_elem = current->next;
		ft_del_swapint(current, del);
		current = next_elem;
	}
	free(*p_lst);
	*p_lst = NULL;
}

void	free_all(t_swap *swap)
{
	ft_lstclear(&swap->move, free);
	ft_stack_clear(&swap->stack_a, free);
	ft_stack_clear(&swap->stack_b, free);
	free(swap);
}
