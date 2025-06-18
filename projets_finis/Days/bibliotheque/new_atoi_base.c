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
				return (0);
			}
			j++;
		}
		if (base[i] == '-' || base[i] == '+' || base[i] == ' ')
			return (0);
		i++;
	}
	return (base_size);
}

int	find_number(char nb, char *base, int base_size)
{
	int	i;

	i = 0;
	while (i <= base_size)
	{
		if (nb == base[i])
			return (i);
		i++;
	}
	return (0);
}

int	ft_atoi_base(char *str, char *base)
{
	int	minus;
	int	number;
	int	base_size;

	if (!base_check(base))
		return (0);
	base_size = base_check(base);
	minus = 0;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minus++;
		str++;
	}
	number = 0;
	while (*str != '\0' && *str == base[find_number(*str, base, base_size - 1)])
	{	
		number = number * base_size + (find_number(*str, base, base_size - 1));
		str++;
	}
	if (minus % 2)
		return (-number);
	return (number);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	base[] = "0123456789abcdef";
// 	char *str = "-800000001";

// 	printf("%d\n",ft_atoi_base(str, base));
// 	return (0);
// }
