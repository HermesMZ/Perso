/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:11:53 by mzimeris          #+#    #+#             */
/*   Updated: 2025/06/19 00:45:48 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_del_swapint(t_swap_int *p_elem)
{
	if (!p_elem)
		return ;
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
		ft_del_swapint(current);
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
