/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 17:37:27 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 14:11:28 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>
#include "rush01.h"

bool	try_value(char **tab, int *pos, int value, int size)
{
	if (!is_empty(tab[pos[0]][pos[1]]))
		return (true);
	if (!check_double(tab, pos, value, size))
	{
		return (false);
	}
	tab[pos[0]][pos[1]] = value + '0';
	return (true);
}

bool	check_all_views(char **tab, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (!check_views(tab, (int []){i, i}, size))
			return (false);
		i++;
	}
	return (true);
}

bool	check_next_value(char **tab, int size, int *pos)
{
	int		new_pos[2];
	char	**new_tab;

	new_tab = cp_tab(tab, size);
	if (!new_tab)
		return (write(2, "Error\n", 6), true);
	if (pos[1] == size && pos[0] != size)
	{
		new_pos[0] = pos[0] + 1;
		new_pos[1] = 1;
		if (check_line(tab, pos, size))
			if (resolve(new_tab, size, new_pos))
				return (free_tab(new_tab), true);
	}
	else if (pos[1] != size)
	{
		new_pos[0] = pos[0];
		new_pos[1] = pos[1] + 1;
		if (resolve(new_tab, size, new_pos))
			return (free_tab(new_tab), true);
	}
	free_tab(new_tab);
	return (false);
}

bool	resolve(char **tab, int size, int *pos)
{
	int		value;

	value = 1;
	while (value <= size)
	{
		if (try_value(tab, pos, value, size))
		{
			if (pos[0] == size && pos[1] == size)
			{
				if (check_all_views(tab, size))
				{
					print_tab(tab, size);
					return (true);
				}
			}
			else if (check_next_value(tab, size, pos))
				return (true);
		}
		value++;
		tab[pos[0]][pos[1]] = ' ';
	}
	return (false);
}
