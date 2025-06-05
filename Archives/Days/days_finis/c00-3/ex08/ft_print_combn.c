/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:48:07 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/20 15:10:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n);
void	ft_printchar(char c);
int	ft_print_start(int n);


int	main(void)
{
	ft_print_combn(5);
	return (0);
}

void 	ft_print_combn(int n)
{
	chiffres = ft_print_start(n);
	for ( i = 0, i <10, i++)
	{
		ft_printchar(chiffres[i] + '0');
	}
}

int	ft_print_start(int n)
{
	int	chiffres_depart[10];
	int	i;

	i = 0;
	while (i < n)
	{
		chiffres_depart[i] = i;
		i++;
	}
	return (&chiffres_depart);
}
	
void	ft_printchar(char c)
{
	write(1, &c, 1);
}
