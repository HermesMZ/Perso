/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:15:11 by mzimeris          #+#    #+#             */
/*   Updated: 2025/02/25 15:05:55 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <bsd/string.h>
//cc ft_strlcat.c -lbsd    

int		counts(char *a);
unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int	main(void)
{
	char	dest[50] = "desti";
	char	src[50] = "nation";
	unsigned int	size = 20;
	printf(" FT_STRLCAT \n");
	printf("%s \n", dest);
	printf("return : %d\n",ft_strlcat(dest, src, size));
	printf("%s \n\n\n", dest);
	char	dest1[50] = "desti";
	char	src1[50] = "nation";
	printf(" STRLCAT \n");
	printf("%s \n", dest1);
	printf("return : %ld\n",strlcat(dest1, src1, size));
	printf("%s \n", dest1);
	return (0);
}
*/

unsigned int	count(char *a)
{
	unsigned int	count;

	count = 0;
	while (a[count])
		count++;
	return (count);
}

unsigned int	min_size(unsigned int count_dest, unsigned int count_src,
unsigned int size)
{
	if (size < count_dest)
		return (count_src + size);
	return (count_src + count_dest);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count_src;
	unsigned int	count_dest;
	unsigned int	i;

	count_dest = count(dest);
	count_src = count(src);
	i = 0;
	if (size != 0)
	{
		{
			while (src[i] && count_dest + i < size -1)
			{
				dest[count_dest + i] = src[i];
				i++;
			}
			dest[count_dest + i] = 0;
		}
	}
	return (min_size(count_dest, count_src, size));
}
