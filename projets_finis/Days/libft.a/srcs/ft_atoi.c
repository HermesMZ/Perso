/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:13:19 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/27 16:50:12 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	minus;
	int	number;

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
	while (*str >= '0' && *str <= '9')
	{	
		number = number * 10 + (*str - '0');
		str++;
	}
	if (minus % 2)
		return (-number);
	return (number);
}
