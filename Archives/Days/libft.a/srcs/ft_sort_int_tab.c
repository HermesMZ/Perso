/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:55:05 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/22 23:38:40 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b);

int	is_bigger(int *tab, int size)
{
	int	i;
	int	max_index;

	max_index = 0;
	i = 1;
	while (i < size)
	{
		if (tab[i] >= tab[max_index])
			max_index = i;
		i++;
	}
	return (max_index);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	imax;
	int	max_index;

	imax = size -1;
	while (imax != 0)
	{
		max_index = is_bigger(tab, imax);
		ft_swap(&tab[max_index], &tab[imax]);
		imax --;
	}
}
