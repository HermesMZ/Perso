/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzimeris <mzimeris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:52:32 by mzimeris          #+#    #+#             */
/*   Updated: 2025/03/02 13:30:16 by admoufle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	*ft_memset(void	*ptr, int size, char c)
{
	char	*cptr;
	int		i;

	i = 0;
	cptr = ptr;
	while (i < size)
		cptr[i++] = c;
	return (ptr);
}

char	*ft_strdup(char *str)
{
	char	*tmp;
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	**cp_tab(char **tab, int x)
{
	char	**new;
	int		i;

	i = 0;
	if (!tab)
		return (NULL);
	new = malloc(sizeof(char *) * (x + 3));
	if (!new)
		return (NULL);
	new[x + 2] = NULL;
	while (tab[i])
	{
		new[i] = ft_strdup(tab[i]);
		if (!new[i])
			return (free_tab(new), NULL);
		i++;
	}
	return (new);
}

char	**create_tab(int x)
{
	char	**new;
	int		i;

	new = malloc(sizeof(char *) * (x + 3));
	if (!new)
		return (NULL);
	i = 0;
	new[x + 2] = NULL;
	while (i < x + 2)
	{
		new[i] = malloc(sizeof(char) * (x + 3));
		if (!new[i])
			return (free_tab(new), NULL);
		ft_memset(new[i], x + 2, ' ');
		new[i][x + 2] = '\0';
		i++;
	}
	return (new);
}
