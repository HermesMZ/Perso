/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 14:32:51 by mzimeris          #+#    #+#             */
/*   Updated: 2025/07/08 15:40:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_values(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (tab[i] == tab[j])
			{
				free(tab);
				return (0);
			}
			j++;
		}
		i++;
	}
	free(tab);
	return (1);
}

int	check_argv(const char *str)
{
	int		sign;
	long	number;

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
	if (*str && (*str < '0' || *str > '9' ))
		return (0);
	number *= sign;
	if (number > 2147483647 || number < -2147483648)
		return (0);
	return (number);
}

int	check_input(int argc, char *argv[])
{
	int	i;
	int	*tab;

	tab = malloc(sizeof(int) * (argc - 1));
	if (!tab)
		return (0);
	i = 1;
	while (i <= argc - 1)
	{
		if (!check_argv(argv[i]))
		{
			free(tab);
			return (0);
		}
		else
			tab[i] = ft_atoi(argv[i]);
		i++;
	}
	if (!check_values(tab, argc - 1))
		return (0);
	return (1);
}
