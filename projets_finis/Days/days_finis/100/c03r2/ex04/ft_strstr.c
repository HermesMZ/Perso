/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:37:11 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/27 17:14:13 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int	main(void)
{
	char	str[] = "abfcdefgh";
	char	to_find[] = "h";
	char	*shot = ft_strstr(str, to_find);
	char	*shot2 = strstr(str, to_find);


	printf("string        = %s\nto_find       = %s\n", str, to_find);
	printf("resulat  FT   = %s\n", shot);
	printf("resulat  STD  = %s\n", shot2);
	return (0);
}
*/
char	*ft_strstr(char *str, char *to_find)
{
	char	*str_point;
	char	*to_find_point;

	if (!to_find[0])
		return (str);
	while (*str != '\0')
	{
		str_point = str;
		to_find_point = to_find;
		while (*to_find_point != '\0' && *str_point == *to_find_point)
		{
			str_point++;
			to_find_point++;
		}
		if (*to_find_point == '\0')
			return (str);
		str++;
	}
	return (0);
}
