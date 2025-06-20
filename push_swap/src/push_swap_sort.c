/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/20 18:19:41 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	merge_stacks_count(t_swap *swap, t_swap_int *dst, int count, t_swap_int *src)
{
	ft_printf("+3");
	ft_printf("dst->value %d, count %d; src->value %d\n", dst->value, count, src->value);
	ft_printf("dst stack ");
	debug_print_stack_from(swap, dst);
	ft_printf("\nsrc stack ");
	debug_print_stack_from(swap, src);
	
	int				i;
	t_swap_int		*next;

	i = 0;
	if (!src || count <= 0)
		return ;
	rotate_to(swap, dst);
	rotate_to(swap, src);
	debug_print_stacks(swap);
	ft_printf("debuuuuuuuuuug\n");
	while (i < count && src)
	{
		next = src->next;
		if (src->index > dst->index && src->stack == swap->stack_a)
			ft_push(swap, src);
		else if (src->index < dst->index && src->stack == swap->stack_b)
			ft_push(swap, src);

		src = next;
		i++;
	}
	// ft_printf("3-");

}

t_swap_int *stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current, int *push_count)
{
	// ft_printf("+2");
	ft_printf("pivot : %d, current : %d\n", pivot->index, current->index);
	t_swap_int *last_pushed = NULL;
	if (current->index > pivot->index && !current->locked)
	{
		ft_push(swap, current);
		last_pushed = current;
		(*push_count)++;
	}
	else
		ft_rotate(swap, current);
	// ft_printf("2-\n");
	
	return last_pushed;
}

void	recursive_split_call(t_swap *swap, t_swap_int *first, int count, int depth)
{
	ft_printf("+1");

	t_swap_int	*pivot;
	t_swap_int	*current;
	t_swap_int	*last_pushed;
	int			i;
	int			push_count;

	debug_print_stacks(swap);
	pivot = find_median(first, count);
	pivot->locked = 1;
	current = first;
	last_pushed = NULL;
	push_count = 0;
	i = 0;
	while (i < count)
	{
		t_swap_int *res = stack_split(swap, pivot, current, &push_count);
		if (res)
			last_pushed = res;
		current = pivot->stack->first;
		i++;
	}
	// Partie triée avec push
	if (push_count > 3)
		quick_sort_stack(swap, last_pushed, push_count, depth + 1);
	else
		hard_sort(swap, last_pushed, push_count);
	// Partie restante
	if ((count - push_count) > 3)
		quick_sort_stack(swap, current->prev, count - push_count, depth + 1);
	else
		hard_sort(swap, current->prev, count - push_count);
	pivot->locked = 0;
	merge_stacks_count(swap, current->prev, push_count, last_pushed);
ft_printf("1-\n");

	debug_print_stacks(swap);
}




void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count, int depth)
{
	if (!first || count <= 1)
		return ;
	rotate_to(swap, first);
	if (count > 2)
		recursive_split_call(swap, first, count, depth);
}



// void merge_stacks_count(t_swap *swap, t_swap_int *dst, t_swap_int *src, int count)
// {
// 	int i;
	
// 	i = 0;
	
// 	ft_printf("meeeeeeeeeeeeeeeeeeeeeeeerge\n");

// 	if (!src || count <= 0)
// 		return;
// 	rotate_to(swap, dst);
// 	rotate_to(swap, src);
// 	while (i < count && src)
// 	{
// 		t_swap_int *next = src->next;

// 		// Si on fusionne vers A (ordre croissant)
// 		if (dst->stack == swap->stack_a)
// 		{
// 			while (dst->stack->first && src->index > dst->stack->first->index)
// 				ft_rotate(swap, dst->stack->first);
// 		}
// 		// Si on fusionne vers B (ordre décroissant)
// 		else
// 		{
// 			while (dst->stack->first && src->index < dst->stack->first->index)
// 				ft_rotate(swap, dst->stack->first);
// 		}

// 		ft_push(swap, src); // push src vers dst
// 		src = next;
// 		i++;
// 	}
// 	debug_print_stacks(swap);
// }


// t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current, int *push_count)
// {
// 	t_swap_int	*last_pushed;
// 	last_pushed = NULL;
// 	if (current->index > pivot->index && !current->locked)
// 	{
// 		ft_push(swap, current);
// 		last_pushed = current;
// 		(*push_count)++;
// 	}
// 	else
// 		ft_rotate(swap, current);
// 	return (last_pushed);
// }



// void recursive_split_call(t_swap *swap, t_swap_int *first, int count, int depth)
// {
//     t_swap_int *pivot;
//     t_swap_int *current;
//     t_swap_int *last_pushed;
//     int i;
//     int push_count;

//     pivot = find_median(first, count);
//     pivot->locked = 1;

//     ft_printf("\n\n== [DEPTH %d] RECURSIVE SPLIT ==\n", depth);
//     ft_printf("Stack: %s | Pivot value: %d (Index: %d) | Count: %d\n",
//         (pivot->stack == swap->stack_a) ? "A" : "B",
//         pivot->value,
//         pivot->index,
//         count
//     );

//     current = first;
//     push_count = 0;
//     last_pushed = NULL;
//     i = 0;

//     while (i < count)
//     {
//         t_swap_int *result = stack_split(swap, pivot, current, &push_count);
//         if (result)
//             last_pushed = result;
//         current = pivot->stack->first;
//         i++;
//     }

//     ft_printf("[DEPTH %d] Split done. Pushed: %d | Remaining: %d\n", depth, push_count, count - push_count);
// 	// Trie récursivement
// 	if (push_count <= 3)
// 		hard_sort(swap, last_pushed, push_count);
// 	else
// 		quick_sort_stack(swap, last_pushed, push_count, depth + 1);

// 	if ((count - push_count) <= 3)
// 		hard_sort(swap, current->prev, count - push_count);
// 	else
// 		quick_sort_stack(swap, current->prev, count - push_count, depth + 1);

// 	pivot->locked = 0;
	
// 	merge_stacks_count(swap, current->stack->first, last_pushed->stack->first, push_count);
// }

// void quick_sort_stack(t_swap *swap, t_swap_int *first, int count, int depth)
// {
//     if (!first || count <= 1)
//         return;

//     ft_printf("=== [DEPTH %d] QUICK_SORT ===\n", depth);
//     ft_printf("Stack: %s | First value: %d | Index: %d | Count: %d\n",
//         (first->stack == swap->stack_a) ? "A" : "B",
//         first->value,
//         first->index,
//         count
//     );

//     rotate_to(swap, first);

//     if (count > 2)
//         recursive_split_call(swap, first, count, depth + 1);

// }


// t_swap_int	*stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current, int *push_count)
// {
// 	t_swap_int	*last_pushed;
// 	last_pushed = NULL;
// 	if (current->index > pivot->index && !current->locked)
// 	{
// 		ft_push(swap, current);
// 		last_pushed = current;
// 		(*push_count)++;
// 	}
// 	else
// 		ft_rotate(swap, current);
// 	return (last_pushed);
// }

// void	recursive_split_call(t_swap *swap, t_swap_int *first, int count)
// {
// 	t_swap_int	*pivot;
// 	t_swap_int	*current;
// 	t_swap_int	*last_pushed;
// 	int			i;
// 	int			push_count;

// 	// pivot = first;
// 	pivot = find_median(first, count);
// 	pivot->locked = 1;
// 	current = first;
// 	push_count = 0;
// 	last_pushed = NULL;
// 	i = 0;
// 	while (i < count)
// 	{
// 		t_swap_int *result;
		
// 		result = stack_split(swap, pivot, current, &push_count);
// 		if (result != NULL)
// 			last_pushed = result; 
// 		current = pivot->stack->first;
// 		i++;
// 	}
// 	if (push_count > 0)
// 		quick_sort_stack(swap, last_pushed, push_count);
// 	if (count - push_count > 0)
// 		quick_sort_stack(swap, current->prev, count - push_count);
// 	pivot->locked = 0;
// }

// void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
// {
// 	if (!first || count <= 1)
// 		return ;
// 	rotate_to(swap, first);
// 	if (count > 2)
// 	{
// 		ft_printf("%d count\n", count);
// 		recursive_split_call(swap, first, count);
// 	}
// 	else
// 		return ;
// }

// 	// debug_print_stacks(swap);
