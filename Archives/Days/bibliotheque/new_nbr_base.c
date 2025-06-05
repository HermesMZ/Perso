/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:12 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/04 17:34:13 by mzimeris         ###   ########.fr       */
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
		return (0);
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
			return (0);
		i++;
	}
	return (0);
}

void	ft_putnbr(int nb, char *base, int base_size)
{
	int	i;
	int	final_number[20];
	int	sign;

	sign = 1;
	if (nb == 0)
		write(1, &base[0], 1);
	if (nb && nb < 0)
	{
		sign = -1;
		write(1, "-", 1);
	}
	i = 0;
	while (nb)
	{
		final_number[i] = nb % base_size;
		nb = nb / base_size;
		i++;
	}
	while (i-- > 0)
	{
		ft_putchar((base[final_number[i] * sign]));
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	base_size;
	long	number;

	number = nbr;
	base_size = ft_strlen(base);
	if (!base_check(base))
	{
		ft_putnbr(number, base, base_size);
	}	
}

// int	main(void)
// {
// 	char	base[] = "gftr";
// 	int	nbr = 0;

// 	ft_putnbr_base(nbr, base);
// 	return (0);
// }
