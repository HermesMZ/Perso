/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 16:14:39 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 14:22:46 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_empty(char c)
{
	return (c == ' ');
}

bool	check_double(char **tab, int *pos, int val, int size)
{
	int	i;

	i = 1;
	while (i <= size)
	{
		if (tab[pos[0]][i] == val + '0')
			return (false);
		if (tab[i][pos[1]] == val + '0')
			return (false);
		i++;
	}
	return (true);
}

int	count_view(char **tab, int *pos, int size, int *move)
{
	int		i;
	int		nb_view;
	int		uppest;
	char	c;

	i = 1;
	uppest = 0;
	nb_view = 0;
	while (i <= size)
	{
		c = tab[pos[0] + i * move[0]][pos[1] + move[1] * i];
		if (!is_empty(c))
		{
			if (c > uppest)
			{
				uppest = c;
				nb_view++;
			}
		}
		i++;
	}
	return (nb_view);
}

bool	check_line(char **tab, int *pos, int size)
{
	int	view_limit;

	view_limit = tab[pos[0]][0] - '0';
	if (count_view(tab, (int []){pos[0], 0}, size,
		(int []){0, 1}) != view_limit)
		return (false);
	view_limit = tab[pos[0]][size + 1] - '0';
	if (count_view(tab, (int []){pos[0], size + 1}, size,
		(int []){0, -1}) != view_limit)
		return (false);
	return (true);
}

bool	check_views(char **tab, int *pos, int size)
{
	int	view_limit;

	view_limit = tab[pos[0]][0] - '0';
	if (count_view(tab, (int []){pos[0], 0}, size,
		(int []){0, 1}) != view_limit)
		return (false);
	view_limit = tab[pos[0]][size + 1] - '0';
	if (count_view(tab, (int []){pos[0], size + 1}, size,
		(int []){0, -1}) != view_limit)
		return (false);
	view_limit = tab[0][pos[1]] - '0';
	if (count_view(tab, (int []){0, pos[1]}, size,
		(int []){1, 0}) != view_limit)
		return (false);
	view_limit = tab[size + 1][pos[1]] - '0';
	if (count_view(tab, (int []){size + 1, pos[1]}, size,
		(int []){-1, 0}) != view_limit)
		return (false);
	return (true);
}
