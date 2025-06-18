/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 01:22:10 by zoum              #+#    #+#             */
/*   Updated: 2025/06/18 21:10:44 by mzimeris         ###   ########.fr       */
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
// int					sorted;
	struct s_stack		*stack;
}	t_swap_int;

typedef struct s_stack
{
	t_swap_int	*first;
	t_swap_int	*last;
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
void		quick_sort_stack(t_swap *swap, t_swap_int *first, int count);
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

void		first_cleaning(t_swap *swap);

void		debug_print_stacks(t_swap *swap);

#endif /*PUSH_SWAP_H*/
