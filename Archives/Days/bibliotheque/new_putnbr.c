/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:03:25 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/06 15:03:28 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	putnbr(int nb)
{
	int	i;
	int	final_number[100];
	int	sign;

	sign = 1;
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	i = 0;
	while (nb)
	{
		final_number[i] = nb % 10;
		nb = nb / 10;
		i++;
	}
	while (i-- > 0)
	{
		ft_putchar((final_number[i] * sign) + '0');
	}
}

// int	main(void)
// {
// 	putnbr(0);
// 	return (0);
// }
