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

char	*ft_strndup(char *str, int size)
{
	char	*tmp;
	int		i;

	tmp = malloc(sizeof(char) * (size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	if (!str)
		tmp[i] = '\0';
	while (i < size && str[i] != '\0')
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

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
	int (i), (k);
	i = 0;
	k = 0;
	while (k != size)
	{
		while (is_charset(str[i], charset))
			str++;
		while (!is_charset(str[i], charset))
			i++;
		splitted[k++] = ft_strndup(str, i);
		str = str + i + 1;
		i = 0;
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

	return (splitted);
}

#include <stdio.h>
int main(void)
{
    // char str[] = "*le=";
    char str[] = "*le===split*-c'est=la*vie--";
    char charset[] = "*-=";
    char **splitted;

    int i = 0;
    splitted = ft_split(str, charset);
    while (splitted[i])
    {
        printf("%s\n", splitted[i]);
        i++;
    }
    i = 0;
    while (splitted[i])
    {
        free(splitted[i]);
        i++;
    }
    free(splitted);
}

