/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .save_push_swap_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/20 03:00:15 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// static void	merge_split(t_swap *swap, t_swap_int *first, t_stack *to, int count)
// {
// 	int			i;

// 	ft_printf(" ======================== MERGE ======================== \n");
// 	if (!first)
// 		return ((void)ft_printf("merge first is NULL\n"));
// 	if (!to)
// 	{
// 		if (first->stack == swap->stack_a)
// 			to = swap->stack_b;
// 		else
// 			to = swap->stack_a;
// 	}
// 	// ft_printf("first->value %d to->value %d \n", first->value, to_first->value);
// 	// debug_print_stacks(swap);

// 	i = 0;
// 	rotate_to(swap, first);
// 	rotate_to(swap, to->first);
// 	// debug_print_stacks(swap);

// 	while (i < count)
// 	{
// 		if (first->index < to->first->index && first->index > to->first->prev->index)
// 			ft_push(swap, first);
// 		else if (first->index > to->first->index && first->index < to->first->next->index)
// 		{
// 			ft_rotate(swap, to->first);
// 			ft_push(swap, first);
// 		}
// 		i++;
// 	}
// 	// debug_print_stacks(swap);
// 	ft_printf(" ========================= END ========================= \n");
// }

// static t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot,
// 	t_swap_int **current, int *push_count)
// {
// 	t_swap_int	*last_pushed;
// 	t_swap_int	*next;

// 	if (!*current)
// 		return (NULL);
// 	next = (*current)->next;
// 	if (next->stack == swap->stack_a)
// 		last_pushed = swap->stack_b->first;
// 	else
// 		last_pushed = swap->stack_a->first;
// 	// ft_printf("current %d pivot %d \n", (*current)->value, pivot->value);
// 	if ((*current)->index >= pivot->index)
// 	{
// 		ft_push(swap, *current);
// 		last_pushed = *current;
// 		(*push_count)++;
// 	}
// 	else
// 		ft_rotate(swap, (*current));
// 	*current = next;
// 	// debug_print_stacks(swap);
// 	return (last_pushed);
// }

static t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot, int *push_count)
{
	t_swap_int	*top;
	t_swap_int	*last_pushed;

	// 5 on vérifie si on doit push ou rotate
	last_pushed = NULL;
	top = pivot->stack->first;
	if (top->index > pivot->index)
	{
		ft_push(swap, top);
		last_pushed = top;
		(*push_count)++;
	}
	else
		ft_rotate(swap, top);
	return (last_pushed);
}


void	recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	t_swap_int	*last_pushed;
	int			i;
	int			push_count;
	
	// 3 mettre le pivot au median pour faciliter le suivi. Trouvé dans la pile de first
	pivot = find_median(first, count);
	// ft_printf(" =================NEW PIVOT = %d - count = %d  - first = %d ================== \n", pivot->value, count, first->value);
	// debug_print_stacks(swap);
	current = first;
	push_count = 0;
	last_pushed = NULL;
	i = 0;
	// 4 tant qu'on a pas traité count éléments on appelle stack_split
	while (i != count)
	{
		last_pushed = stack_split(swap, pivot, &push_count);
		// 6 mise à jour du current sur la base du pivot qui ne peut pas être push
		current = pivot->stack->first;
		i++;
	}
	// debug_print_stacks(swap);
	if (count - push_count > 0)
		quick_sort_stack(swap, current, count - push_count);
	if (push_count > 0)
		quick_sort_stack(swap, last_pushed, push_count);
}


void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	if (!first || count <= 1)
		return ;
	rotate_to(swap, first);
	if (count == 2)
	{
		if (first->value > first->next->value)
			ft_swap(swap, first);
		return ;
	}
	if (count > 2)
		recursive_split_call(swap, first, count);
}

// void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
// {
// 	// 0 count est le nombre d'éléments de la stack à spliter
// 	if (!first)
// 		return ;
// 	// 1 retour à la tête de la pile à splitter
// 	rotate_to(swap, first);
// 	// 2 appel récursif seulement s'il y a plus de 2 éléments à traiter
// 	if (count > 2)
// 		recursive_split_call(swap, first, count);
// 	// if (count == 2)
// 	// {
// 	// 	if (first->stack == swap->stack_a && first->index > first->next->index)
// 	// 		ft_swap(swap, first);
// 	// 	if (first->stack == swap->stack_b && first->index < first->next->index)
// 	// 		ft_swap(swap, first);
// 	// }
// }
