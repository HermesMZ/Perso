/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 18:34:02 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/21 14:33:55 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	temp_d;
	int	temp_m;

	if (*b != 0)
	{
		temp_d = *a / *b;
		temp_m = *a % *b;
		*a = temp_d;
		*b = temp_m;
	}
}
