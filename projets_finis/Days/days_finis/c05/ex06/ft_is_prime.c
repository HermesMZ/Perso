/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:52:02 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 14:52:04 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	else if (nb <= 3)
		return (1);
	else if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	else
	{
		i = 5;
		while (i * i <= nb)
		{
			if ((nb % i == 0) || (nb % (i + 2) == 0))
				return (0);
			i += 6;
		}
	}
	return (1);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d    %d\n", 13, ft_is_prime(13));
// 	printf("%d    %d\n", 313, ft_is_prime(313));
// 	printf("%d    %d\n", 199, ft_is_prime(199));
// 	return (0);
// }