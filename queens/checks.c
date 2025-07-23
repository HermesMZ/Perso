/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:35:24 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/23 18:36:27 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queens.h"


static int	check_lines(int *table, int value, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (table[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	check_diags(int *table, int value, int size)
{
	int	i;
	int	free_col;

	free_col = 0;
	while (free_col < size && table[free_col] != ' ')
		free_col++;
	i = 0;
	while (i < free_col)
	{
		if (free_col - i == table[free_col] - table[i])
			return (1);
		i++;
	}
	return (0);
}

int	check_new_queen(int *table, int value, int size)
{
	int	res;

	res = 0;
	res += check_diags(table, value, size);
	res += check_lines(table, value, size);
	if (res > 0)
		return (1);
	return (0);
}
