/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:33:33 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/10 13:28:29 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

// Write a function that will concatenate all the strings pointed by strs 
// separated sep.
// • size is the number of strings in strs
// • if size is 0, you must return an empty string that you can free().
int	sep_length(int size, char *sep)
{
	int	i;

	if (!size)
		return (1);
	i = 0;
	while (sep[i] != '\0')
		i++;
	return (i * (size -1));
}

int	str_lengths(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	nb_char;

	if (size == 0)
		return (1);
	i = 0;
	nb_char = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			nb_char++;
			j++;
		}
		i++;
	}
	return (nb_char + sep_length(size, sep) + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*final_string;

	int (i), (j), (k);
	final_string = malloc(sizeof(char) * (str_lengths(size, strs, sep)));
	if (!final_string)
		return (NULL);
	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			final_string[k++] = strs[i][j++];
		}
		j = 0;
		if (i != size - 1)
			while (sep[j])
				final_string[k++] = sep[j++];
		i++;
	}
	final_string[k] = '\0';
	return (final_string);
}
/*
#include <stdio.h>

int	main(void)
{
	char	*strs[50];
	char	*sep;
	char	*final_string;

	sep = "---";
	strs[0] = "Geek";
	strs[1] = "For";
	strs[2] = "Geeks";
	final_string = ft_strjoin(3, strs, sep);
	printf("%s\n", final_string);
	free(final_string);
	return (0);
}
*/
