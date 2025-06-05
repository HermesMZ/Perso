/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:16:44 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 14:10:46 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	main(void)
{
	char	dest[15] = {'\0'};
	char	src[15] = "Hello";
	unsigned int	n = 3;

	printf("Avant : **%s** \n", dest);
	ft_strncpy(dest, src, n);
	printf("Apres : **%s** \n", dest);
}
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}		
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
