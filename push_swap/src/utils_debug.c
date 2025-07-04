/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:08:42 by zoum              #+#    #+#             */
/*   Updated: 2025/06/26 18:12:43 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	debug_print_stack_from(t_swap *swap, t_swap_int *start)
{
	if (!start || !start->stack)
	{
		ft_printf("Invalid stack.\n");
		return ;
	}
	if (start->stack == swap->stack_a)
		ft_printf("=== src = STACK A ===\n");
	else
		ft_printf("=== src = STACK B ===\n");
}

void	debug_print_split(t_heads *heads)
{
	int			i;
	int			j;
	t_swap_int	*pushed;
	t_swap_int	*remaining;

	pushed = heads->pushed;
	remaining = heads->remaining;
	ft_printf(" =========================================================================== \n");
	ft_printf("splitted groups : push %d, remain %d\n", heads->push_count, heads->remaining_count);
	i = 0;
	j = 0;

	ft_printf("pushed :    ");
	while (i < heads->push_count)
	{
		ft_printf("%2d ", pushed->value);
		pushed = pushed->next;
		i++;
	}
	ft_printf("\nremaining : ");
	while (j < heads->remaining_count)
	{
		ft_printf("%2d ", remaining->value);
		remaining = remaining->next;
		j++;
	}
	ft_printf("\n =========================================================================== \n");
	ft_printf("\n");
}

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
	ft_printf("\n%10c %10c\n%10d %10d\n\n", 'a', 'b', stack_a->len, stack_b->len);
	ft_printf("min-a %4d min-b %4d\n", swap->stack_a->min, swap->stack_b->min);
	ft_printf("max-a %4d max-b %4d\n\n", swap->stack_a->max, swap->stack_b->max);
	i = 0;
	// while (i < stack_a->len || i < stack_b->len)
	while (i < stack_a->len || i < stack_b->len)
	{
		if (a)
		{
			if (a->locked)
				ft_printf("X%8dX ", a->value);
			else
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
	ft_printf("commands done : %d\n", ft_lstsize(swap->move) - 1);
}

void	debug_print_locked(t_swap *swap)
{
	t_swap_int	*a;
	t_stack		*stack_a;
	size_t		i;

	stack_a = swap->stack_a;
	a = stack_a->first;
	ft_printf("\n ==================== LOCKED ==================== \n");
	i = 0;
	while (i < stack_a->len)
	{
		if (a)
		{
			if (a->locked)
				ft_printf("%10d\n", a->value);
			else
				ft_printf("%10s\n");
			if (a->next && i + 1 < stack_a->len)
				a = a->next;
			else
				a = NULL;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("commands done : %d\n", ft_lstsize(swap->move) - 1);
}
