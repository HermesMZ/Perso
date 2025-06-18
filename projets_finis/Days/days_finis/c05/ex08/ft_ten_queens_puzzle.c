/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:53:09 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/03 20:17:17 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_line(char *str)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

// fonctions de check

int	check_lines(char *str, int value)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (str[i] == value)
			return (0);
		i++;
	}
	return (1);
}

int	check_diag(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 10)
	{
		j = i + 1;
		while (j <= 10)
		{
			if ((str[j] - str[i]) == (j - i)
				|| (str[i] - str[j]) == (j - i))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	resolve(char *str, int index, int *count)
{
	int	value;

	if (index == 10 && check_diag(str))
	{
		(*count)++;
		print_line(str);
		return (1);
	}
	value = '0';
	while (value <= '9')
	{
		if (str[index] == ' ' && check_lines(str, value))
		{
			(str[index] = value);
			resolve(str, index + 1, count);
		}
		str[index] = ' ';
		value++;
	}
	return (0);
}

int	ft_ten_queens_puzzle(void)
{
	char	str[11];
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (i <= 10)
	{
		str[i] = ' ';
		i++;
	}	
	str[10] = '\0';
	resolve(str, 0, &count);
	return (count);
}
/*
#include <stdio.h>
int	main(void)
{
	int result = ft_ten_queens_puzzle();
    printf("%d\n", result);
	return (0);
}
*/
