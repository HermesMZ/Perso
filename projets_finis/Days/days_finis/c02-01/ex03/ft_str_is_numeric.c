/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/24 13:18:15 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

int	ft_str_is_numeric(char *str);

int	main(void)
{
	char	str1[20] = "abcdexyzA4CDEXYZ";
	char	str_test[6] = "02123";
	int	a;

	printf("%s\n", str1);
	a = ft_str_is_numeric(str1);
	printf("%d\n", a);	
	printf("%s\n", str_test);
	a = ft_str_is_numeric(str_test);
	printf("%d\n", a);	
	return (0);
}
*/
int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		++i;
	}
	return (1);
}
