/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admoufle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 13:29:08 by admoufle          #+#    #+#             */
/*   Updated: 2025/03/02 13:52:55 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_tab(char **tab, int size)
{
	int		i;
	int		j;
	char	separator[2];

	if (!tab)
		return ;
	separator[0] = ' ';
	separator[1] = '\n';
	i = 1;
	while (i <= size && tab[i])
	{
		j = 1;
		while (j <= size && tab[i] + j)
		{
			write(1, tab[i] + j, 1);
			write(1, &separator[j == size], 1);
			j++;
		}
		i++;
	}
}

void	fill_view(char **tab, char *str, int x)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i <= x)
	{
		tab[0][i] = str[j * 2];
		tab[x + 1][i] = str[j * 2 + x * 2];
		tab[i][0] = str[x * 4 + j * 2];
		tab[i][x + 1] = str[x * 6 + j * 2];
		i++;
		j++;
	}
}
