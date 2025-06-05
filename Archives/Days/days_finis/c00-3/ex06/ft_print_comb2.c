/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 19:05:00 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/20 11:28:56 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);
void	ft_print_char(char c);

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_char(a / 10 + '0');
			ft_print_char(a % 10 + '0');
			ft_print_char(' ');
			ft_print_char(b / 10 + '0');
			ft_print_char(b % 10 + '0');
			if (a != 98)
			{
				ft_print_char(',');
				ft_print_char(' ');
			}
			b++;
		}
		a++;
	}
}

void	ft_print_char(char c)
{
	write(1, &c, 1);
}
