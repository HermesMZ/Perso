/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 14:17:11 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

char	*ft_strlowcase(char *str);

int	main(void)
{
	char	str1[20] = "abcdexyzA4CDEXYZ";
	char	str_test[6] = "ABCDE";


	printf("%s\n", str1);
	ft_strlowcase(str1);
	printf("%s\n", str1);
	printf("%s\n", str_test);
	ft_strlowcase(str_test);
	printf("%s\n", str_test);
	return (0);
}
*/
char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		++i;
	}
	return (str);
}
