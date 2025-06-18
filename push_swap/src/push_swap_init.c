/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 16:46:38 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 20:43:52 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int	is_sa_beneficial(int *current_end, size_t *count,
//     t_swap_int **current_node, t_swap *swap, size_t *i)
// {
// 	int	swapped;
// 	int	original;

// 	swapped = (*current_node)->next->value;
// 	original = (*current_node)->value;
// 	if (swapped == swap->min
// 		&& *current_end == swap->max)
// 	{
// 		*current_end = swapped;
// 		(*count)++;
// 		*current_node = (*current_node)->next;
// 		(*i)++;
// 		return (1);
// 	}
// 	else if (swapped >= *current_end
// 		&& swapped < original)
// 	{
// 		*current_end = swapped;
// 		(*count)++;
// 		*current_node = (*current_node)->next;
// 		(*i)++;
// 		return (1);
// 	}
// 	return (0);
// }

// static size_t	count_following(t_swap *swap, t_swap_int *start)
// {
// 	size_t		count;
// 	size_t		i;
// 	int			end_val;
// 	t_swap_int	*current;

// 	i = 0;
// 	count = 0;
// 	end_val = start->value;
// 	current = start;
// 	while (i < swap->stack_a->len)
// 	{
// 		if (is_sa_beneficial(&end_val, &count, &current, swap, &i))
// 			continue ;
// 		else if ((current->value == swap->min
// 				&& end_val == swap->max)
// 			|| (current->value >= end_val
// 				&& current->value < current->next->value))
// 		{
// 			count++;
// 			end_val = current->value;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	return (count);
// }

// static t_swap_int	*find_best_start(t_swap *swap)
// {
// 	size_t		max_count;
// 	size_t		current_count;
// 	size_t		i;
// 	t_swap_int	*best_start;
// 	t_swap_int	*current;

// 	max_count = 0;
// 	i = 0;
// 	best_start = swap->stack_a->first;
// 	current = swap->stack_a->first;
// 	while (i < swap->stack_a->len)
// 	{
// 		current_count = count_following(swap, current);
// 		if (current == swap->stack_a->last && current->value == swap->max)
// 			break ;
// 		if (current_count > max_count)
// 		{
// 			max_count = current_count;
// 			best_start = current;
// 		}
// 		current = current->next;
// 		i++;
// 	}
// 	return (best_start);
// }
// ft_printf("====== best_start %d, max_count %d\n",
// best_start->value, max_count);

static void	set_min_max(t_swap *swap)
{
	int			min;
	int			max;
	size_t		i;
	t_swap_int	*current;

	i = 0;
	min = swap->stack_a->first->value;
	max = swap->stack_a->first->value;
	current = swap->stack_a->first;
	while (i <= swap->stack_a->len)
	{
		if (current->value < min)
			min = current->value;
		if (current->value > max)
			max = current->value;
		current = current->next;
		i++;
	}
	swap->max = max;
	swap->min = min;
}

t_swap	*swap_init(t_swap *swap, char *argv[], size_t len)
{
	size_t	i;
	t_list	*move;

	move = ft_lstnew("start");
	swap = malloc(sizeof(t_swap));
	if (!swap)
		return (NULL);
	swap->stack_a = ft_stack_init();
	swap->stack_b = ft_stack_init();
	if (!swap->stack_a || !swap->stack_b)
		return (NULL);
	i = 1;
	while (i <= len)
	{
		ft_stack_add_back(swap->stack_a, ft_atoi(argv[i]));
		swap->stack_a->last->stack = swap->stack_a;
		i++;
	}
	swap->stack_a->first->prev = swap->stack_a->last;
	swap->stack_a->last->next = swap->stack_a->first;
	set_min_max(swap);
	// swap->best_start = find_best_start(swap);
	fill_index(swap->stack_a);
	swap->move = move;

	// i = 0;
	// t_swap_int *current = swap->stack_a->first;
	// while (i < len)
	// {
	// 	ft_printf("stack_a[%d] = %d\n", current->index, current->value);
	// 	i++;
	// 	current = current->next;
	// }

	return (swap);
	
}
