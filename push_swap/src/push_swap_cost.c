/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_merge.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 02:05:53 by zoum              #+#    #+#             */
/*   Updated: 2025/06/20 02:14:19 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

static int	calc_min_rot(int pos, int len)
{
	if (pos <= len / 2)
		return (pos);
	return (pos - len);
}

static int	find_pos(t_stack *stack, t_swap_int *node)
{
	t_swap_int	*cur;
	int			pos;

	pos = 0;
	cur = stack->first;
	while (cur && cur != node)
	{
		cur = cur->next;
		pos++;
	}
	return (pos);
}

static int	calc_insert_pos(t_stack *a, int value)
{
	t_swap_int	*cur;
	int			i;
	int			len;
	int			best_pos;

	cur = a->first;
	len = a->len;
	best_pos = 0;
	i = 0;
	while (i < len)
	{
		if ((value > cur->value && value < cur->next->value)
			|| (cur->value > cur->next->value
			&& (value > cur->value || value < cur->next->value)))
		{
			best_pos = (i + 1) % len;
			break ;
		}
		cur = cur->next;
		i++;
	}
	return (best_pos);
}


t_cost	calc_cost_to_insert(t_swap *swap, t_swap_int *node_b)
{
	t_cost		cost;
	int			pos_a;
	int			pos_b;
	int			rot_a;
	int			rot_b;

	pos_b = find_pos(swap->stack_b, node_b);
	pos_a = calc_insert_pos(swap->stack_a, node_b->value);
	rot_a = calc_min_rot(pos_a, swap->stack_a->len);
	rot_b = calc_min_rot(pos_b, swap->stack_b->len);

	cost.rot_a = rot_a;
	cost.rot_b = rot_b;
	cost.node_b = node_b;
	if ((rot_a >= 0 && rot_b >= 0) || (rot_a <= 0 && rot_b <= 0))
	{
		if (ft_abs(rot_a) > ft_abs(rot_b))
			cost.total = ft_abs(rot_a);
		else
			cost.total = ft_abs(rot_b);
	}
	else
		cost.total = ft_abs(rot_a) + ft_abs(rot_b);
	return (cost);
}

