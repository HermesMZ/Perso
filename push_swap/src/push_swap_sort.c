/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/24 18:14:42 by mzimeris         ###   ########.fr       */
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
	ft_printf("pivot %d\n", pivot->value);
	while (i < count)
	{
		if (current->value > pushed->value)
			pushed = current;
		current = current->next;
		i++;
	}
	ft_printf("hed\n");

	return (current);
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
	// int			count;
	ft_printf(" **************** MERGE **************** \n");
	debug_print_split((*heads));
	debug_print_stacks(swap);
	// rotate_to(swap, (*heads)->pushed);
	// rotate_to(swap, (*heads)->remaining);
	// ft_printf("rotate\n");
	
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
ft_printf("HEADS pushed %d remain %d\n", (*heads)->pushed->value, (*heads)->remaining->value);
	i = 0;
	j = 0;
	while (i < (*heads)->push_count)
	{
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
			
			// debug_print_stacks(swap);
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
		}
	}
	// (*heads)->remaining = to->first;
	// debug_print_split((*heads));
	
	if (to == swap->stack_a)
	{
		ft_printf("rotate");	
		ft_printf("%d", (*heads)->remaining->value);	
		rotate_to(swap, find_min_in_split((*heads)->remaining, (*heads)->push_count));
		// (*heads)->pushed = to->first;
	}
	// else
	// {
	// 	(*heads)->remaining = to->first;
	// }

	ft_printf(" **************** MERGE FINISHED **************** \n");
			debug_print_stacks(swap);
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
	heads->pushed = find_pushed_head_split(pivot, count);
	heads->remaining = find_remaining_head_split(pivot);
	heads->push_count = 0;
	heads->remaining_count = 0;
	i = 0;

	ft_printf(" **************** first %d **************** \n", first->value);
	ft_printf(" **************** SPLIT **************** \n");
	debug_print_split((heads));
	debug_print_stacks(swap);

	while (i < count)
	{
		stack_split(swap, pivot, current, &heads);
		current = pivot->stack->first;
		i++;
	}
	ft_printf(" **************** SPLIT FINISHED **************** \n");
	// debug_print_split((heads));
	// debug_print_stacks(swap);
	// debug_print_split(heads);
	if (heads->push_count > 3)
	{
		// ft_printf("recursif sur les pushs\n");
		quick_sort_stack(swap, heads->pushed, heads->push_count);
	}
	if ((heads->remaining_count) > 3)
	{
		// ft_printf("recursif sur le restant\n");
		quick_sort_stack(swap, heads->remaining, heads->remaining_count);
	}
	pivot->locked = 0;
	if (heads->push_count <= 3)
	{
		hard_sort(swap, heads->pushed, heads->push_count);
	}
	if (heads->remaining_count <= 3)
	{
		rotate_to(swap, heads->remaining);
		hard_sort(swap, heads->remaining, heads->remaining_count);
	}
	heads->pushed = heads->pushed->stack->first;

	ft_printf(" **************** pushed %d **************** \n", heads->pushed->value);
	ft_printf(" **************** remain %d **************** \n", heads->remaining->value);
	
	// on arrive au dernier petit split possible
	if (swap->stack_a->len <= 3)
	{
		free(heads);
		return (NULL);
	}

	merge_stacks_count(swap, &heads);
	// ft_printf(" **************** current %d **************** \n", current->value);
	// // rotate_to(swap, heads->remaining);
	// debug_print_split(heads);
	// debug_print_stacks(swap);
	free(heads);
	return (heads->remaining);
}

	// debug_print_split(heads);
	// mettre les heads a jour en fonction de stack_a / stack_b min / max
	// ft_printf("enter merging\n");
	// debug_print_split(heads);
	// debug_print_stacks(swap);
	// ft_printf("end merging\n");
		// rotate_to(swap, current);
	// rotate_to(swap, heads->pushed);
	// ft_printf(" **************** first %d **************** \n", first->value);




void	quick_sort_stack(t_swap *swap, t_swap_int *first, int count)
{
	t_swap_int	*tmp = NULL;

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
		// (*heads)->pushed = current;
		debug_print_stacks(swap);
		(*heads)->push_count++;
	}
	else
	{
		ft_rotate(swap, current);
		debug_print_stacks(swap);

		(*heads)->remaining_count++;
	}


	return (heads);
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