/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:14:54 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/05 19:14:58 by mzimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Create a function that splits a string of character depending on another 
// string of characters.
// • You’ll have to use each character from the string charset as a separator.
// • The function returns an array where each element of the array contains the 
// address of a string wrapped between two separators. The last element of 
// that array should equal to 0 to indicate the end of the array.
// • There cannot be any empty strings in your array. Get your own conclusions
//  accordingly.
// • The string given as argument won’t be modifiable.
#include <stdlib.h>

char	*ft_strndup(char *str, int size);

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	strings_count(char *str, char *charset)
{
	int (i), (is_in_word), (count);
	count = 0;
	is_in_word = 0;
	if (!str || !charset)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (!is_charset(str[i], charset) && !is_in_word)
		{
			is_in_word = 1;
			count ++;
		}
		else if (is_charset(str[i], charset))
			is_in_word = 0;
		i++;
	}
	return (count);
}

void	create_strings(char *str, char *charset, char **splitted, int size)
{
	int (i), (j), (k);
	i = 0;
	j = 0;
	k = 0;
	while (k != size)
	{
		while (is_charset(str[i], charset))
			i++;
		while (!is_charset(str[i + j], charset))
			j++;
		splitted[k] = ft_strndup(&str[i], j);
		i += j;
		j = 0;
		k++;
	}
	splitted[k] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	int		size;
	char	**splitted;

	if (!str || !charset)
		return (0);
	size = strings_count(str, charset);
	splitted = malloc(sizeof(char *) * (size + 1));
	if (!splitted)
		return (NULL);
	create_strings(str, charset, splitted, size);
	splitted[size] = NULL;

	return (splitted);
}
/*
int main(int argc, char **argv)
{
    if (argc != 3)
		return (0);

	char **splitted;

    int i = 0;
    splitted = ft_split(argv[1], argv[2]);
    while (splitted[i])
    {
        printf("%s\n", splitted[i]);
        i++;
    }
	if (splitted[i] == NULL)
		printf("splitted[i]) == NULL");

    i = 0;
    while (splitted[i])
    {
        free(splitted[i]);
        i++;
    }
    free(splitted);
	return (0);
}
*/
