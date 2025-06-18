/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 21:21:47 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 14:13:10 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

char	*ft_strupcase(char *str);

int	main(void)
{
	char	str1[20] = "abcdexyzA4CDEXYZ";
	char	str_test[6] = "abcde";


	printf("%s\n", str1);
	ft_strupcase(str1);
	printf("%s\n", str1);
	printf("%s\n", str_test);
	ft_strupcase(str_test);
	printf("%s\n", str_test);
	return (0);
}
*/
char	*ft_strupcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		++i;
	}
	return (str);
}
