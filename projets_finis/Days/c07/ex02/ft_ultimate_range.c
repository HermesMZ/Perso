/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:33:19 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/04 17:33:23 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	j;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (!*range)
	{
		range = NULL;
		return (-1);
	}
	i = 0;
	j = min;
	while (i < max - min)
	{
		(*range)[i] = j;
		j++;
		i++;
	}
	return (max - min);
}

// int	ft_atoi(char *str)
// {
// 		int	minus;
// 		int	number;

// 		minus = 0;
// 		while ((*str >= '\t' && *str <= '\r') || *str == ' ')
// 			str++;
// 		while (*str == '+' || *str == '-')
// 		{
// 				if (*str == '-')
// 					minus++;
// 				str++;
// 			}
// 	number = 0;
// 	while (*str >= '0' && *str <= '9')
// 	{	
// 			number = number * 10 + (*str - '0');
// 			str++;
// 		}
// 		if (minus % 2)
// 			return (-number);
// 		return (number);
// 	}

// 	#include <stdio.h>
// 	int	main(int argc, char **argv)
// {
// 	int	*range;
// 	int i;

// 	if (argc < 2)
// 		return (1);
// 	ft_ultimate_range(&range, ft_atoi(argv[1]), ft_atoi(argv[2]));
// 	i = 0;
// 	while (i < ft_atoi(argv[2]) - ft_atoi(argv[1]))
// 	{
// 		printf("%d ", range[i]);
// 		i++;
// 	}
// 	free(range);
// 	return (0);
// }
