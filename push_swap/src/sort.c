/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 00:11:33 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*tmp;
	static int	i = 0;

	tmp = NULL;
	ft_printf("qs_stack call count : %d\n", i);
	i++;
	if (!first || count <= 1)
		return ;
	if (is_circularly_sorted(swap->stack_a) == 1
		&& is_circularly_sorted(swap->stack_b) == -1)
		return ;
	rotate_to(swap, first);
	if (count > 2)
	{
		tmp = recursive_split_call(swap, first, count);
	}
	rotate_to(swap, tmp);
}
