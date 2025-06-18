/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_debug.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:08:42 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 21:03:33 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stacks(t_swap *swap)
{
	t_swap_int	*a;
	t_swap_int	*b;
	t_stack		*stack_a;
	t_stack		*stack_b;
	size_t		i;

	stack_a = swap->stack_a;
	stack_b = swap->stack_b;
	a = stack_a->first;
	b = stack_b->first;
	// ft_printf("Debug - print stacks\n%10c %10c\n", 'a', 'b');
	ft_printf("\n%10c %10c\n%10d %10d\n\n", 'a', 'b', stack_a->len, stack_b->len);
	i = 0;
	while (i < stack_a->len || i < stack_b->len)
	{
		if (a)
		{
			ft_printf("%10d ", a->value);
			if (a->next && i + 1 < stack_a->len)
				a = a->next;
			else
				a = NULL;
		}
		else
			ft_printf("%11c", ' ');
		if (b)
		{
			ft_printf("%10d", b->value);
			if (b->next && i + 1 < stack_b->len)
				b = b->next;
			else
				b = NULL;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("commands done : %d\n", ft_lstsize(swap->move));
}
