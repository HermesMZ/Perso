/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 13:28:43 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/28 13:28:48 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

int ft_atoi_base(char *str, char *base);


int	ft_strlen(char *str)
{
	int	i;
	
	i = 0;
	while (str[i] != '\0')
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

int get_decimal(char c, char *base)
{
	int	*decimal;
	decimal = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
}

int	ft_atoi_base(char *str, char *base)
{ // valeurs des lettres
	if (!base_check(base))
	{
		int	minus;
		int	number;
		int base_size;
		
		base_size = ft_strlen(base);
		minus = 0;
		while ((*str > '\t' && *str < '\r') || *str == ' ')
			str++;
		while (*str == '+' || *str == '-')
		{
			if (*str == '-')
				minus++;
			str++;
		}
		number = 0;
		while (*str >= base[0] && *str <= base[base_size - 1])
		{	
			number = number * base_size + (*str);
			str++;
		}
		if (minus % 2)
			return (-number);
		return (number);
	}
	return (0);
}

int	main(void)
{
	char	str[50] = "1d20d";
	char	base[] = "0123456789abcdef";

	printf("%d\n", ft_atoi_base(str, base));
}
	*/