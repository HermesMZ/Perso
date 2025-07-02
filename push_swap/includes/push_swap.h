/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:22:10 by zoum              #+#    #+#             */
/*   Updated: 2025/07/02 21:29:13 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft.h"

typedef struct s_swap_int
{
	struct s_swap_int	*prev;
	struct s_swap_int	*next;
	int					value;
	int					index;
	int					locked;
	struct s_stack		*stack;
}	t_swap_int;

typedef struct s_heads
{
	t_swap_int	*pushed;
	t_swap_int	*remaining;
	int			push_count;
	int			remaining_count;
}	t_heads;

typedef struct s_cost
{
	int			ra;
	int			rb;
	int			rr;
	int			total;
	t_swap_int	*elem;
}	t_cost;

typedef struct s_stack
{
	t_swap_int	*first;
	t_swap_int	*last;
	int			min;
	int			max;
	size_t		len;
}	t_stack;

typedef struct s_swap
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	int			min;
	int			max;
	t_swap_int	*best_start;
	t_list		*move;
}	t_swap;

t_stack		*ft_stack_init(void);
void		ft_stack_add_back(t_stack *stack, int value);
void		ft_stack_add_front(t_stack *stack, int value);

t_swap		*swap_init(t_swap *swap, char *argv[], size_t len);
void		fill_index(t_stack *stack);
t_swap_int	*find_index(t_stack *stack, int i);
void		quick_sort(int tab[], int first, int last);
t_swap_int	*find_median(t_swap_int *first, int count);

int			is_sorted(size_t length, t_swap_int *elem);
int			is_circularly_sorted(t_stack *stack);
// void		quick_sort_stack(t_swap *swap, t_swap_int *first, int count);
void		hard_sort(t_swap *swap, t_swap_int *elem, int count);
void		rotate_to(t_swap *swap, t_swap_int *elem);
int			r_or_rr(t_swap_int *target);

t_cost		calc_cost_to_insert(t_swap *swap, t_swap_int *node_b);

void		first_cleaning(t_swap *swap);

void		free_all(t_swap *swap);

void		update_min_max(t_swap *swap, t_swap_int *elem);
void		set_min_max(t_stack *stack);

// sort
void		quick_sort_stack(t_swap *swap, t_swap_int *first, int count);

// split
t_swap_int	*recursive_split_call(t_swap *swap, t_swap_int *first, int count);

// heads
t_heads		*init_heads(int count, t_swap_int *pivot);
t_heads		*update_heads_for_merge(t_swap *swap, t_heads *heads);

// merge
void		merge_to_stack(t_swap *swap, t_heads **heads, t_stack *from, t_stack *to);
void		merge_stacks_count(t_swap *swap, t_heads **heads);
void		anticipate_merge(t_swap *swap, t_heads **heads);

// operations
void		ft_push(t_swap *swap, t_swap_int *elem);
void		ft_swap(t_swap *swap, t_swap_int *elem);
void		ft_swap_ss(t_swap *swap);
void		ft_rotate(t_swap *swap, t_swap_int *elem);
void		ft_rotate_rr(t_swap *swap);
void		ft_reverse_rotate(t_swap *swap, t_swap_int *elem);
void		ft_reverse_rotate_rr(t_swap *swap);

// lock
int			to_lock(t_swap *swap, t_swap_int *elem);
t_swap_int	*find_closest_inf_locked(t_stack *stack_a, t_swap_int *elem);
void		head_update(t_heads *heads);
void		lock_all(t_swap *swap);
// void		lock_all(t_stack *stack_a);

// debug
void		debug_print_stacks(t_swap *swap);
void		debug_print_stack_from(t_swap *swap, t_swap_int *start);
void		debug_print_split(t_heads *heads);
void		debug_print_locked(t_swap *swap);

// split utils
t_swap_int	*find_min_in_split(t_swap_int *elem, int count);
t_swap_int	*find_max_in_split(t_swap_int *elem, int count);
t_swap_int	*find_pushed_head_split(t_swap_int *pivot, int count);
t_swap_int	*find_remaining_head_split(t_swap_int *pivot);
t_swap_int	*find_first_free(t_stack *stack_a);

// min_max
void		set_min_max(t_stack *stack);
void		update_min_max(t_swap *swap, t_swap_int *elem);
void		update_min_max_on_push(t_swap_int *elem);
void		update_min_max_on_pop(t_swap *swap, t_swap_int *elem);

// exec_moves
void		execute_optimal_moves(t_swap *swap, t_cost *cost);

// simple maths
int			ft_abs(int x);
int			ft_min(int a, int b);
int			ft_max(int a, int b);

// cost
t_cost		*init_empty_cost(void);
t_cost		*calculate_node_cost(t_swap *swap, t_swap_int *elem_b);
t_swap_int	*get_target_in_a(t_stack *stack_a, t_swap_int *elem_b);
t_swap_int	*get_target_in_b(t_stack *stack_b, t_swap_int *elem_a);

void		push_back_to_a_optimized(t_swap *swap);
void		free_cost_if_not_null(t_cost **cost);

void		push_chunks(t_swap *swap, int nb_chunks);
void		push_one_chunk(t_swap *swap, int chunk_min, int chunk_max);
int			has_chunk(t_stack *stack, int chunk_min, int chunk_max);
void		rotate_n_times(t_swap *swap, int n);
t_swap_int	*find_next_chunk_elem(t_swap_int *current, int chunk_min,
				int chunk_max);

t_cost		*calculate_cost_for_a_to_b(t_swap *swap, t_swap_int *elem_a);
t_cost		*calculate_cost_for_b_to_a(t_swap *swap, t_swap_int *elem_b);
t_swap_int	*get_target(t_swap *swap, t_swap_int *source);
t_cost		*find_cheapest_element(t_swap *swap, t_stack *source_stack,
				int chunk_min, int chunk_max);


#endif /*PUSH_SWAP_H*/
