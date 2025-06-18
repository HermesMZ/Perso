/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 15:19:31 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/01 17:06:30 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill_col(char **tab, int move, int size, int *pos)
{
	int	i;

	i = 1;
	if (tab[pos[0]][pos[1]] - '0' == size)
	{
		while (i <= size)
		{
			tab[pos[0] + i * move][pos[1]] = i + '0';
			i++;
		}
	}
	else
		tab[pos[0] + 1 * move][pos[1]] = size + '0';
}

void	fill_line(char **tab, int move, int size, int *pos)
{
	int	i;

	i = 1;
	if (tab[pos[0]][pos[1]] - '0' == size)
	{
		while (i <= size)
		{
			tab[pos[0]][pos[1] + i * move] = i + '0';
			i++;
		}
	}
	else
		tab[pos[0]][pos[1] + 1 * move] = size + '0';
}

void	prefill(char **tab, int x)
{
	int	i;

	i = 1;
	while (i <= x)
	{
		if (tab[0][i] == '1' || tab[0][i] == x + '0')
			fill_col(tab, 1, x, (int []){0, i});
		if (tab[x + 1][i] == '1' || tab[x + 1][i] == x + '0')
			fill_col(tab, -1, x, (int []){x + 1, i});
		if (tab[i][0] == '1' || tab[i][0] == x + '0')
			fill_line(tab, 1, x, (int []){i, 0});
		if (tab[i][x + 1] == '1' || tab[i][x + 1] == x + '0')
			fill_line(tab, -1, x, (int []){i, x + 1});
		i++;
	}
}
