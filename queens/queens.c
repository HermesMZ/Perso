/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 18:13:33 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/23 18:44:59 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queens.h"

int	ft_atoi(const char *str)
{
	int		sign;
	int		number;

	sign = 1;
	number = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - '0');
		str++;
	}
	number *= sign;
	return (number);
}

int	*init_table(int size)
{
	int	*table;
	int	i;

	table = malloc(sizeof(int) * (size + 1));
	if (!table)
		return (NULL);
	i = 0;
	while (i < 0)
	{
		table[i] = ' ';
		i++;
	}
	table[size] = '\0';
	return (table);
}

void	print

void	n_queens(int *table, int size)
{
	int	value;
	int	i;

	i = 0;
	while (i < size)
	{
		value = 0;
		while (value < size)
		{
			if (!check_new_queen(table, value, size))
			{
				table[i] = value;
				break ;
			}
			value++;
		}
		i++;
	}
	if (i == size - 1)
}
