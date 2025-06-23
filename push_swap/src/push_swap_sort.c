/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:27:14 by zoum              #+#    #+#             */
/*   Updated: 2025/06/23 18:40:05 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	merge_stacks_count(t_swap *swap, t_swap_int *src, t_swap_int *dst, int count)
{
	int			i;
	t_swap_int	*next;

	ft_printf("src->value %d, count %d; dst->value %d\n", src->value, src->value, count);
	ft_printf("\nsrc stack %d ", src->value);
	debug_print_stack_from(swap, src);
	ft_printf("dst stack %d ", dst->value);
	debug_print_stack_from(swap, dst);

	i = 0;
	if (!src || count <= 0)
		return ;
	ft_printf("Rotate to heads");
	// rotate_to(swap, src);
	// rotate_to(swap, dst);
	debug_print_stacks(swap);
	i = 0;
	while (i < count && src)
	{
		ft_printf("%d - merge count : %d\n", i + 1, count);
		next = src->next;
		if (src->value == swap->max)
		{
			while (src->index - dst->stack->first->index < 5)
				ft_rotate(swap, dst);
			ft_push(swap, src);
			i++;
		}
		// else if ()
		else if ((src->stack == swap->stack_b && src->stack->first->index
				< dst->stack->first->index))
		{
			ft_push(swap, src);
			i++;
		}
		else if ((src->stack == swap->stack_a && src->stack->first->index
				> dst->stack->first->index))
		{
			ft_push(swap, src);
			i++;
		}
		else
			ft_rotate(swap, dst);
		debug_print_stacks(swap);
	ft_printf("head pushed %d head rem %d pushed %d rem %d\n", src->value, dst->value);
			
		src = next;
	}
	if (dst->stack == swap->stack_a)
		rotate_to(swap, dst);
	else
		rotate_to(swap, src);
}

// ft_printf("pivot : %d, current : %d\n", pivot->index, current->index);
t_heads	**stack_split(t_swap *swap, t_swap_int *pivot, t_swap_int *current,
	t_heads **heads)
{

	if (current->index > pivot->index && !current->locked)
	{
		ft_push(swap, current);
		// ft_printf("push %d\n", current->value);
		(*heads)->pushed = current;
		(*heads)->push_count++;
	}
	else
	{
		ft_rotate(swap, current);
		if (!(*heads)->remaining)
			(*heads)->remaining = current;
		// ft_printf("rotate %d\n", current->value);
	}
	return (heads);
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
		
	ft_printf("before split\n");
	debug_print_stacks(swap);
	pivot = find_median(first, count);
	ft_printf("pivot %d\n", pivot->value);
	// ft_printf("heads %d %d\n", heads->pushed->value, heads->remaining->index);
	pivot->locked = 0;
	current = first;
	heads->pushed = NULL;
	heads->remaining = NULL;
	heads->push_count = 0;
	heads->remaining_count = 0;
	i = 0;
	// if (heads->pushed && heads->remaining)
	// {
	// 	rotate_to(swap, heads->pushed);
	// 	rotate_to(swap, heads->remaining);
	// }
	while (i < count)
	{
		stack_split(swap, pivot, current, &heads);
		current = pivot->stack->first;
		i++;
	}
	heads->remaining_count = count - heads->push_count;

	ft_printf("after split\n");
	debug_print_stacks(swap);


	ft_printf("count %d, push_count %d, remaining %d\n", count, heads->push_count, heads->remaining_count);
	// last_pushed->locked = 0;


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
	// last_pushed->locked = 0;
	if (heads->push_count <= 3)
	{
		hard_sort(swap, heads->pushed, heads->push_count);
		heads->pushed = heads->pushed->stack->first;
	}
	if (heads->remaining_count <= 3)
	{
		ft_printf("last_pushed:%i\tadam_test_head:%i\n", heads->pushed->value, heads->remaining->value);
		rotate_to(swap, heads->remaining);
		hard_sort(swap, heads->remaining, heads->remaining_count);
		heads->remaining = heads->remaining->stack->first;
	}
	ft_printf("head pushed %d head rem %d pushed %d rem %d\n", heads->pushed->value, heads->remaining->value, heads->push_count, heads->remaining_count);
	ft_printf("after sort\n");
	debug_print_stacks(swap);
	merge_stacks_count(swap, heads->pushed, heads->remaining, heads->push_count);
	heads->remaining = heads->remaining->stack->first;

	ft_printf("after merge\n");
	ft_printf("head pushed %d head rem %d pushed %d rem %d\n", heads->pushed->value, heads->remaining->value, heads->push_count, heads->remaining_count);
	// rotate_to(swap, heads->pushed);
	debug_print_stacks(swap);
	free(heads);
}




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
