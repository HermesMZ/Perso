/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:34:03 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/04 17:34:05 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a function that returns the result of the conversion of the string 
// nbr from a base base_from to a base base_to.
// • nbr, base_from, base_to may be not writable.
// • nbr will follow the same rules as ft_atoi_base (from an other module). 
// Beware of ’+’, ’-’ and whitespaces.
// • The number represented by nbr must fit inside an int.
// • If a base is wrong, NULL should be returned.
// • The returned number must be prefix only by a single and uniq ’-’ 
// if necessary, no whitespaces, no ’+’
#include <stdlib.h>

int	ft_strlen(char *str);
int	base_check(char *base);
int	ft_digits_count(int atoi, int to_size);
int	find_number(char nb, char *base, char base_size);

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	number;
	int	base_size;
	int digit;

	base_size = base_check(base);
	if (!base)
		return (0);
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	number = 0;
	while ((digit = find_number(*str, base, base_size)) != -1)
	{	
		number = number * base_size + digit;
		str++;
	}
	return (number * sign);
}

void	ft_putnbr_base(char *result, int atoi, char *base)
{
	static int	i = 0;
	int			base_size;
	long		number;

	number = atoi;
	base_size = ft_strlen(base);
	if (number < 0)
	{
		result[i++] = '-';
		number *= -1;
	}
	if (number >= base_size)
	{
		ft_putnbr_base(result, number / base_size, base);
		ft_putnbr_base(result, number % base_size, base);
	}
	else
		result[i++] = base[number];
	result[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char *(result);
	int (atoi), (result_size);
	char (from_size), (to_size);
	from_size = base_check(base_from);
	to_size = base_check(base_to);
	if (!from_size || !to_size)
		return (NULL);
	atoi = ft_atoi_base(nbr, base_from);
	result_size = ft_digits_count(atoi, to_size);
	result = malloc(sizeof(char) * result_size);
	if (!result)
		return (NULL);
	if (atoi == 0)
		result[0] = base_to[0];
	else
		ft_putnbr_base(result, atoi, base_to);
	result[result_size + 1] = '\0';
	return (result);
}

#include <stdio.h>

int	main(void)
{
	// -2147483648
	// 255 ff
	char	base_from[] = "01";
	char	base_to[] = "0123456789abcdef";
	char	nbr[] = "-10000000000000000000000000000000";
	char *result = ft_convert_base(nbr, base_from, base_to);
	int		i = 0;
	while (result[i])
	{
		printf("%c", result[i]);
		i++;
	}
	printf("\n");

	free(result);

	return (0);
}
