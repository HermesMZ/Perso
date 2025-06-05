/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MZimeris <MZimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 23:18:25 by MZimeris          #+#    #+#             */
/*   Updated: 2025/04/30 23:18:28 by MZimeris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_splitted(char **splitted)
{
	int	i;

	i = 0;
	while (splitted[i])
	{
		free(splitted[i]);
		splitted[i++] = NULL;
	}
	free(splitted);
}

static char	*ft_strndup(const char *str, int size)
{
	char	*tmp;
	int		i;

	if (!str)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * (size + 1));
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

static int	strings_count(const char *s, char c)
{
	int	i;
	int	is_in_word;
	int	count;

	count = 0;
	is_in_word = 0;
	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && !is_in_word)
		{
			is_in_word = 1;
			count ++;
		}
		else if (s[i] == c)
			is_in_word = 0;
		i++;
	}
	return (count);
}

static void	create_strings(const char *s, char c, char **splitted, int size)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (k < size)
	{
		while (s[i] == c)
			i++;
		j = 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		splitted[k] = ft_strndup(&s[i], j);
		if (!splitted[k])
			return (free_splitted(splitted));
		i += j;
		j = 0;
		k++;
	}
	splitted[size] = NULL;
}

char	**ft_split(const char *s, char c)
{
	int		size;
	char	**splitted;

	if (!s)
		return (NULL);
	size = strings_count(s, c);
	splitted = (char **)malloc(sizeof(char *) * (size + 1));
	if (!splitted)
		return (NULL);
	create_strings(s, c, splitted, size);
	return (splitted);
}
