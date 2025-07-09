/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoum <zoum@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 21:11:52 by zoum              #+#    #+#             */
/*   Updated: 2025/07/08 23:39:44 by zoum             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

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

int			check_input(char *argv[]);
t_stack		*ft_stack_init(void);
void		ft_stack_add_back(t_stack *stack, int value);
t_swap		*swap_init(t_swap *swap, char *argv[], size_t len);
int			is_sorted(size_t length, t_swap_int *elem);
int			is_circularly_sorted(t_stack *stack);
void		set_min_max(t_stack *stack);
void		update_min_max(t_swap *swap, t_swap_int *elem);
void		update_min_max_on_push(t_swap_int *elem);
void		update_min_max_on_pop(t_swap *swap, t_swap_int *elem);
int			error(void);
void		free_all(t_swap *swap);

void		ft_push(t_swap *swap, t_swap_int *elem);
void		ft_swap(t_swap *swap, t_swap_int *elem);
void		ft_swap_ss(t_swap *swap);
void		ft_rotate(t_swap *swap, t_swap_int *elem);
void		ft_rotate_rr(t_swap *swap);
void		ft_reverse_rotate(t_swap *swap, t_swap_int *elem);
void		ft_reverse_rotate_rr(t_swap *swap);

int			check_and_do_move(t_swap *swap, char *move);

// debug
void		debug_print_stacks(t_swap *swap);

#endif /*CHECKER_H*/