/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:13:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 15:28:54 by admoufle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <unistd.h>

bool	ft_isnum(char c)
{
	if (c > '0' && c <= '9')
		return (true);
	return (false);
}

int	check_input(char *str)
{
	int	i;
	int	size;

	i = 0;
	while (str && str[i])
	{
		if (i % 2 == 0 && !ft_isnum(str[i]))
			return (write(2, "Error\n", 6), -1);
		else if (i % 2 && str[i] != ' ')
			return (write(2, "Error\n", 6), -1);
		i++;
	}
	if (!i || (str && str[i - 1] == ' '))
		return (write(2, "Error\n", 6), -1);
	size = (i + 1) / 2;
	if (!(size % 4) && size / 4 <= 9)
		return (size / 4);
	return (write(2, "Error\n", 6), -1);
}
