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
	int	(base_size), (i), (j);
	base_size = ft_strlen(base);
	if (base_size < 2)
		return (0);
	i = 0;
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

int	ft_digits_count(int atoi, int to_size)
{
	int		i;
	long	n;

	n = atoi;
	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n != 0)
	{
		n /= to_size;
		i++;
	}
	return (i);
}

int	find_number(char nb, char *base, char base_size)
{
	int	i;

	i = 0;
	while (i < base_size)
	{
		if (nb == base[i])
			return (i);
		i++;
	}
	return (-1);
}
