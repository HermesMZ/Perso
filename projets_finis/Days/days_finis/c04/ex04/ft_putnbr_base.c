/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:24:18 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/27 17:24:21 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	base_check(char *base)
{
	int	base_size;
	int	i;
	int	j;

	i = 0;
	base_size = ft_strlen(base);
	if (base_size < 2)
		return (1);
	while (i < base_size)
	{
		j = i + 1;
		while (j < base_size)
		{
			if (base[i] == base [j])
			{
				return (1);
			}
			j++;
		}
		if (base[i] == '-' || base[i] == '+')
			return (1);
		i++;
	}
	return (0);
}

void	ft_putnbr(long nb, char *base, int base_size)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb, base, base_size);
	}
	if (nb >= base_size)
	{
		ft_putnbr(nb / base_size, base, base_size);
		ft_putnbr(nb % base_size, base, base_size);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_size;
	long	number;

	if (!base_check(base))
	{
		number = nbr;
		base_size = ft_strlen(base);
		ft_putnbr(number, base, base_size);
	}	
}
/*
int	main(void)
{
	char	base[] = "01";
	int		nbr = 10;

	(void)base;
	ft_putnbr_base(nbr, base);
	return (0);
}
*/
