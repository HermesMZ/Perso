/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:22:10 by zoum              #+#    #+#             */
/*   Updated: 2025/06/25 14:31:15 by mzimeris         ###   ########.fr       */
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
	int			rot_a;
	int			rot_b;
	int			total;
	t_swap_int	*node_b;
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
void		hard_sort_3(t_swap *swap, t_swap_int *elem);

void		rotate_to(t_swap *swap, t_swap_int *elem);
int			r_or_rr(t_swap_int *target);

void		ft_push(t_swap *swap, t_swap_int *elem);
void		ft_swap(t_swap *swap, t_swap_int *elem);
void		ft_swap_ss(t_swap *swap);
void		ft_rotate(t_swap *swap, t_swap_int *elem);
void		ft_rotate_rr(t_swap *swap);
void		ft_reverse_rotate(t_swap *swap, t_swap_int *elem);
void		ft_reverse_rotate_rrr(t_swap *swap);

t_cost		calc_cost_to_insert(t_swap *swap, t_swap_int *node_b);

void		first_cleaning(t_swap *swap);

void		debug_print_stacks(t_swap *swap);
void		debug_print_stack_from(t_swap *swap, t_swap_int *start);
void		debug_print_split(t_heads *heads);


void		quick_sort_stack(t_swap *swap, t_swap_int *first, int count);
t_swap_int	*recursive_split_call(t_swap *swap, t_swap_int *first, int count);

void		free_all(t_swap *swap);

void		update_min_max(t_swap *swap, t_swap_int *elem);
void		set_min_max(t_stack *stack);
t_swap_int	*find_max_in_split(t_swap_int *elem, int count);

#endif /*PUSH_SWAP_H*/
