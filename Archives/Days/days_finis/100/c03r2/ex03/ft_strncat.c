/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:09:14 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 22:34:09 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb);

int	main(void)
{
	char	dest[50] = "desti";
	char	src[50] = "nation";
	unsigned int	nb = 1;

//	printf("ft_       : %s\n",ft_strncat(dest, src, nb));
	printf("   strcat : %s\n",strncat(dest, src, nb));
	return (0);
}
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	count_src;
	int				count_dest;

	count_dest = 0;
	count_src = 0;
	while (dest[count_dest])
		count_dest++;
	while (src[count_src] && count_src < nb)
	{
		dest[count_dest] = src[count_src];
		count_src++;
		count_dest++;
	}
	dest[count_dest] = '\0';
	return (dest);
}
