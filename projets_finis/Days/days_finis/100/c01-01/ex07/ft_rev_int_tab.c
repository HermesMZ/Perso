/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:54:46 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/21 12:52:40 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	indice_debut;
	int	indice_fin;
	int	temp;

	indice_debut = 0;
	indice_fin = size - 1;
	temp = 0;
	while (indice_debut < indice_fin)
	{
		temp = tab[indice_debut];
		tab[indice_debut] = tab[indice_fin];
		tab[indice_fin] = temp;
		indice_debut++;
		indice_fin--;
	}
}
