/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:10:44 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/23 18:41:41 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEENS_H
# define QUEENS_H

# include <unistd.h>

int			ft_atoi(const char *str);
int			*init_table(int size);
int			check_new_queen(int *table, int value, int size);
void		n_queens(int *table, int size);


#endif /*QUEENS_H*/