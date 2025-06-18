/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/24 13:26:06 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

int	ft_str_is_printable(char *str);

int	main(void)
{
	char	str1[20] = "abcdexyz\nA4CDEXYZ";
	char	str_test[20] = "ABCDE";
	int	a;

	printf("%s\n", str1);
	a = ft_str_is_printable(str1);
	printf("%d\n", a);	
	printf("%s\n", str_test);
	a = ft_str_is_printable(str_test);
	printf("%d\n", a);	
	return (0);
}
*/
int	ft_str_is_printable(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32)
			return (0);
		++i;
	}
	return (1);
}
