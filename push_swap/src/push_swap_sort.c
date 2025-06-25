/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/25 14:25:46 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_heads	**stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current,
			t_heads **heads);

t_swap_int	*find_min_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*min;
	int			i;
	t_swap_int	*current;

	min = elem;
	current = elem;
	i = 0;
	while (i < count)
	{
		if (current->index < min->index)
			min = current;
		current = current->next;
		i++;
	}
	return (min);
}


t_swap_int	*find_max_in_split(t_swap_int *elem, int count)
{
	t_swap_int	*max;
	int			i;
	t_swap_int	*current;

	current = elem;
	max = find_index(elem->stack, elem->stack->min);
	i = 0;
	while (i < count)
	{
		if (current->index > max->index)
			max = current;
		current = current->next;
		i++;
	}
	return (max);
}

t_swap_int	*find_pushed_head_split(t_swap_int *pivot, int count)
{
	t_swap_int	*current;
	int			i;
	t_swap_int	*pushed;

	i = 0;
	ft_printf("pus\n");
	current = pivot->stack->first;
	pushed = current;
	while (i < count)
	{
		ft_printf("current : %d / pushed : %d\n", current->value, pushed->value);
		if (current->value > pivot->value)
			pushed = current;
		current = current->next;
		i++;
	}
	ft_printf("pivot %d head %d\n", pivot->value, current->value);

	ft_printf("hed\n");

	return (pushed);
}

t_swap_int	*find_remaining_head_split(t_swap_int *pivot)
{
	t_swap_int	*current;

	ft_printf("bouh\n");
	current = pivot->stack->first;
	ft_printf("pivot %d\n", pivot->value);
	while (current->index > pivot->index)
		current = current->next;
	ft_printf("teille\n");

	return (current);
}

// prendre les heads finales 
// t_swap_int	*find_pushed_head_split(t_swap *swap, t_swap_int *pivot, int count)
// {
// 	t_swap_int	*current;

// 	ft_printf("pus\n");
// 	current = pivot->stack->first;
// 	ft_printf("pivot %d\n", pivot->value);
// 	if (pivot->stack == swap->stack_a)
// 		current = find_index(pivot->stack, pivot->index + 1);
// 	else
// 		current = find_max_in_split(pivot->stack->first, count);
// 	ft_printf("hed\n");

// 	return (current);
// }

// t_swap_int	*find_remaining_head_split(t_swap *swap, t_swap_int *pivot, int count)
// {
// 	t_swap_int	*current;

// 	ft_printf("bouh\n");
// 	current = pivot->stack->first;
// 	ft_printf("pivot %d\n", pivot->value);
// 	if (pivot->stack == swap->stack_a)
// 		find_min_in_split(pivot->stack->first, count);
// 	else
// 		current = pivot;
// 	ft_printf("teille\n");

// 	return (current);
// }



// pushed merged into remaining
void	merge_stacks_count(t_swap *swap, t_heads **heads)
{
	int			i;
	int			j;
	t_stack		*from;
	t_stack		*to;

	ft_printf(" **************** MERGE **************** \n");

	// rotate_to(swap, (*heads)->remaining);
	// rotate_to(swap, (*heads)->pushed);
	if ((*heads)->pushed->stack == swap->stack_a)
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
	debug_print_split((*heads));
	debug_print_stacks(swap);
	i = 0;
	j = 0;
	while (i < (*heads)->push_count)
	{
		ft_printf("i %d - j %d\n", i, j);
		if (to == swap->stack_a)
		{
			if (from->first->index > to->first->index && j < (*heads)->remaining_count)
			{
				ft_rotate(swap, to->first);
				j++;
			}
			else
			{
				ft_push(swap, from->first);
				i++;
			}
		}
		else
		{
			if (from->first->index < to->first->index && j < (*heads)->remaining_count)
			{
				ft_rotate(swap, to->first);
				j++;
			}
			else
			{
				ft_push(swap, from->first);
				i++;
			}
			(*heads)->remaining = (*heads)->remaining->stack->first;
		}
		debug_print_split((*heads));
		debug_print_stacks(swap);
	}
	rotate_to(swap, (*heads)->remaining);
}


t_swap_int	*recursive_split_call(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*pivot;
	t_swap_int	*current;
	int			i;
	t_heads		*heads;

	heads = malloc(sizeof(t_heads));
	if (!heads)
		return (NULL);
	pivot = find_median(first, count);
	pivot->locked = 0;
	current = first;
	heads->remaining = find_remaining_head_split(pivot);
	heads->pushed = find_pushed_head_split(pivot, count);
	heads->push_count = 0;
	heads->remaining_count = 0;
	i = 0;
	debug_print_stack_from(swap, first);
	debug_print_split(heads);
	debug_print_stacks(swap);

	while (i < count)
	{
		stack_split(swap, pivot, current, &heads);
		current = pivot->stack->first;
		i++;
	}
	ft_printf(" **************** SPLIT FINISHED **************** \n");
	// debug_print_stack_from(swap, first);
	debug_print_split(heads);
	debug_print_stacks(swap);
	
	if (heads->push_count > 3 && heads->remaining_count > 3)
	{
		quick_sort_stack(swap, heads->pushed, heads->push_count);
		quick_sort_stack(swap, heads->remaining, heads->remaining_count);
	}
	else if (heads->push_count <= 3 && heads->remaining_count <= 3)
	{
	ft_printf(" ********************* SORT ********************* \n");

		debug_print_split(heads);
		debug_print_stacks(swap);
		hard_sort(swap, heads->pushed, heads->push_count);
		rotate_to(swap, heads->remaining);
		debug_print_stacks(swap);

		hard_sort(swap, heads->remaining, heads->remaining_count);
		heads->remaining = heads->remaining->stack->first;
		heads->pushed = heads->pushed->stack->first;
	ft_printf(" **************** SORT FINISHED **************** \n");
		debug_print_split(heads);
		debug_print_stacks(swap);
	}
	pivot->locked = 0;
	
	// if (swap->stack_a->len <= 3)
	merge_stacks_count(swap, &heads);
	heads->remaining = heads->remaining->stack->first;
	debug_print_split(heads);
	debug_print_stacks(swap);
	if (swap->stack_b->len == 0)
	{
		free(heads);
		return (NULL);
	}
	else
	{
		free(heads);
		return (heads->remaining);
	}
}

void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*tmp = NULL;
	static int	i = 0;

	ft_printf("qs_stack call count : %d\n", i++);
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
	// rotate_to(swap, first);
}

t_heads	**stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current,
	t_heads **heads)
{
	if (current->index > pivot->index && !current->locked)
	{
		ft_push(swap, current);
		(*heads)->push_count++;
	}
	else
	{
		ft_rotate(swap, current);
		(*heads)->remaining_count++;
	}
	return (heads);
}
