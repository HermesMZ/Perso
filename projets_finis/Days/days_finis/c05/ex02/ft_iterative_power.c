/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:50:19 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 14:50:21 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	if (power == 0)
		return (1);
	result = nb;
	while (power > 1)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	printf("%d\n\n", ft_iterative_power(2, 2));
// 	printf("%d\n\n", ft_iterative_power(2, 10));
// 	printf("%d\n\n", ft_iterative_power(-2, 9));
// 	printf("%d\n\n", ft_iterative_power(2, 0));
// 	printf("%d\n\n", ft_iterative_power(0, 0));

// 	return (0);

// }