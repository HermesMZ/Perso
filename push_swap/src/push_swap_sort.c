/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/24 12:56:33 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heads	**stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current,
			t_heads **heads);

// pushed merged into remaining
void	merge_stacks_count(t_swap *swap, t_heads *heads)
{
	int			i;
	int			j;
	t_stack		*from;
	t_stack		*to;

	if (heads->pushed->stack == swap->stack_a)
	{
		to = swap->stack_b;
		from = swap->stack_a;
		ft_printf("merging to stack_b\n");
	}
	else
	{
		to = swap->stack_a;
		from = swap->stack_b;
		ft_printf("merging to stack_a\n");
	}
	debug_print_split(heads);
	debug_print_stacks(swap);

	i = 0;
	j = 0;
	while (i < heads->push_count)
	{
		if (to == swap->stack_a)
		{
			if (from->first->index > to->first->index && j < heads->remaining_count)
			{
				ft_rotate(swap, to->first);
				j++;
			}
			else
			{
				ft_push(swap, from->first);
				i++;
			}
			debug_print_stacks(swap);
		}
		else
		{
			if (from->first->index < to->first->index && j < heads->remaining_count)
			{
				ft_rotate(swap, to->first);
				j++;
			}
			else
			{
				ft_push(swap, from->first);
				i++;
			}
			debug_print_stacks(swap);
		}
	}
	if (to == swap->stack_a)
		rotate_to(swap, heads->remaining);
	ft_printf("end merging\n");
	debug_print_stacks(swap);


}



void	recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;
	t_heads		*heads;

	heads = malloc(sizeof(t_heads));
	if (!heads)
		return ;
	pivot = find_median(first, count);
	pivot->locked = 0;
	current = first;
	heads->pushed = NULL;
	heads->remaining = NULL;
	heads->push_count = 0;
	heads->remaining_count = 0;
	i = 0;
	while (i < count)
	{
		stack_split(swap, pivot, current, &heads);
		current = pivot->stack->first;
		i++;
	}
	heads->remaining_count = count - heads->push_count;
	debug_print_split(heads);

	if (heads->push_count > 3)
	{
		ft_printf("recursif sur les pushs\n");
		quick_sort_stack(swap, heads->pushed, heads->push_count);
	}
	if ((heads->remaining_count) > 3)
	{
		ft_printf("recursif sur le restant\n");
		quick_sort_stack(swap, heads->remaining, heads->remaining_count);
	}
	pivot->locked = 0;
	if (heads->push_count <= 3)
	{
		hard_sort(swap, heads->pushed, heads->push_count);
		heads->pushed = heads->pushed->stack->first;
	}
	if (heads->remaining_count <= 3)
	{
		rotate_to(swap, heads->remaining);
		hard_sort(swap, heads->remaining, heads->remaining_count);
		heads->remaining = heads->remaining->stack->first;
	}

	if (swap->stack_a->len <= 3)
		return ((void)free(heads));
	// debug_print_split(heads);
	// mettre les heads a jour en fonction de stack_a / stack_b min / max
	merge_stacks_count(swap, heads);
	heads->remaining = heads->remaining->stack->first;
	free(heads);
}

// void	merge_stacks_count(t_swap *swap, t_swap_int *src, t_swap_int *dst, int count)
// {
// 	int			i;
// 	t_swap_int	*next;

// 	if (src->stack == swap->stack_a)
// 		ft_printf("merging to stack_b\n");
// 	else
// 		ft_printf("merging to stack_a\n");
// 	debug_print_split(&(t_heads){src, dst, 3, 3});
// 	debug_print_stacks(swap);
// 	if (!src || count <= 0)
// 		return ;
// 	i = 0;
// 	while (i < count && src)
// 	{
// 		next = src->next;
// 		if (src->stack == swap->stack_b)
// 		{
// 			if (src->index == swap->max)
// 			{
// 				while (dst->next->index == dst->index + 1)
// 				{
// 					ft_rotate(swap, dst);
// 					dst = dst->next;
// 				}
// 				ft_push(swap, src);
// 				i++;
// 			}
// 			if (src->stack->first->index < dst->stack->first->index)
// 			{
// 				ft_push(swap, src);
// 				i++;
// 			}
// 			else
// 				ft_rotate(swap, dst);
// 			debug_print_stacks(swap);

// 		}
// 		else
// 		{
// 			if ((src->stack == swap->stack_a && src->stack->first->index
// 					> dst->stack->first->index))
// 			{
// 				ft_push(swap, src);
// 				i++;
// 			}
// 			else
// 				ft_rotate(swap, dst);
// 		}
// 		src = next;
// 	}
// 	if (dst->stack == swap->stack_a)
// 		rotate_to(swap, dst);
// 	else
// 		rotate_to(swap, src);
// 	ft_printf("end merging\n");
// 	debug_print_stacks(swap);


// }



// void	recursive_split_call(t_swap *swap, t_swap_int *first, int count)
// {
// 	t_swap_int	*pivot;
// 	t_swap_int	*current;
// 	int			i;
// 	t_heads		*heads;

// 	heads = malloc(sizeof(t_heads));
// 	if (!heads)
// 		return ;
// 	pivot = find_median(first, count);
// 	pivot->locked = 0;
// 	current = first;
// 	heads->pushed = NULL;
// 	heads->remaining = NULL;
// 	heads->push_count = 0;
// 	heads->remaining_count = 0;
// 	i = 0;
// 	while (i < count)
// 	{
// 		stack_split(swap, pivot, current, &heads);
// 		current = pivot->stack->first;
// 		i++;
// 	}
// 	heads->remaining_count = count - heads->push_count;
// 	debug_print_split(heads);

// 	if (heads->push_count > 3)
// 	{
// 		ft_printf("recursif sur les pushs\n");
// 		quick_sort_stack(swap, heads->pushed, heads->push_count);
// 	}
// 	if ((heads->remaining_count) > 3)
// 	{
// 		ft_printf("recursif sur le restant\n");
// 		quick_sort_stack(swap, heads->remaining, heads->remaining_count);
// 	}
// 	pivot->locked = 0;
// 	if (heads->push_count <= 3)
// 	{
// 		hard_sort(swap, heads->pushed, heads->push_count);
// 		heads->pushed = heads->pushed->stack->first;
// 	}
// 	if (heads->remaining_count <= 3)
// 	{
// 		rotate_to(swap, heads->remaining);
// 		hard_sort(swap, heads->remaining, heads->remaining_count);
// 		heads->remaining = heads->remaining->stack->first;
// 	}

// 	if (swap->stack_a->len <= 3)
// 		return ((void)free(heads));
// 	// debug_print_split(heads);
	
// 	merge_stacks_count(swap, heads->pushed, heads->remaining, heads->push_count);
// 	heads->remaining = heads->remaining->stack->first;
// 	free(heads);
// }




void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{

	if (!first || count <= 1)
		return ;
	if (is_circularly_sorted(swap->stack_a) == 1
		&& is_circularly_sorted(swap->stack_b) == -1)
		return ;
	rotate_to(swap, first);
	if (count > 2)
		recursive_split_call(swap, first, count);
}

t_heads	**stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current,
	t_heads **heads)
{

	if (current->index > pivot->index && !current->locked)
	{
		ft_push(swap, current);
		(*heads)->pushed = current;
		(*heads)->push_count++;
	}
	else
	{
		ft_rotate(swap, current);
		if (!(*heads)->remaining)
			(*heads)->remaining = current;
	}
	return (heads);
}