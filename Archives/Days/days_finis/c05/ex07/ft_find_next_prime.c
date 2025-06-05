/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 14:52:30 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 14:52:32 by mzimeris         ###   ########.fr       */
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

int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb += 1;
	return (nb);
}

// #include <stdio.h>

// int	main(void)
// {
// 	printf("%d    %d\n", 13, ft_find_next_prime(40009));
// 	return (0);
// }